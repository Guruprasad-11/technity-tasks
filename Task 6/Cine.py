import os
import telebot
import requests
import csv

# Get your environment variables
bot_id = "6464336500:AAFYcS0sjezCLiniqlN_I5JF_b2zE_8Nhuw"
omdb_api_key = "abb6bfb0"  # Your OMDb API key

bot = telebot.TeleBot(bot_id)

botRunning = True  # Initialize the bot as running


@bot.message_handler(commands=['start', 'hello'])
def greet(message):
    global botRunning
    botRunning = True
    bot.reply_to(
        message, 'Hello there! I am a bot that will show movie information for you and export it in a CSV file.\n\n')


@bot.message_handler(commands=['stop', 'bye'])
def goodbye(message):
    global botRunning
    botRunning = False
    bot.reply_to(message, 'Bye!\nHave a good time')


@bot.message_handler(func=lambda message: botRunning, commands=['help'])
def helpProvider(message):
    bot.reply_to(message, '1.0 You can use \"/movie MOVIE_NAME\" command to get the details of a particular movie. For eg: \"/movie The Shaw shank Redemption\"\n\n2.0. You can use \"/export\" command to export all the movie data in CSV format.\n\n3.0. You can use \"/stop\" or the command \"/bye\" to stop the bot.')


@bot.message_handler(func=lambda message: botRunning, commands=['movie'])
def getMovie(message):
    if len(message.text.split()) > 1:
        movie_name = " ".join(message.text.split()[1:])
        response = requests.get(
            f"http://www.omdbapi.com/?t={movie_name}&apikey={omdb_api_key}")
        if response.status_code == 200:
            data = response.json()
            if data.get("Response") == "True":
                title = data.get('Title', 'N/A')
                year = data.get('Year', 'N/A')
                imdb_rating = data.get('imdbRating', 'N/A')
                plot = data.get('Plot', 'N/A')
                actors = data.get('Actors', 'N/A')

                movie_info = (
                    f"Title: {title}\n"
                    f"Year: {year}\n"
                    f"IMDb Rating: {imdb_rating}\n"
                    f"Plot: {plot}\n"
                    f"Actors: {actors}\n"
                )

                poster_url = data.get("Poster", '')
                if poster_url and poster_url != "N/A":
                    bot.send_photo(message.chat.id, poster_url, caption=movie_info)
                else:
                    bot.reply_to(message, movie_info)
            else:
                bot.reply_to(message, "Sorry, no results found for that movie.")
        else:
            bot.reply_to(
                message, "Sorry, something went wrong while fetching movie information.")
    else:
        bot.reply_to(
            message, "Please provide the movie name after the /movie command.")


@bot.message_handler(func=lambda message: botRunning, commands=['export'])
def getList(message):
    response = requests.get(
        f"http://www.omdbapi.com/?s=&apikey={omdb_api_key}")  # Fetch a list of movies (replace 's=' with your search query)

    if response.status_code == 200:
        data = response.json()
        movies = data.get("Search", [])

        if movies:
            csv_filename = "movie_data.csv"
            with open(csv_filename, "w", newline="", encoding="utf-8") as csv_file:
                csv_writer = csv.writer(csv_file)
                csv_writer.writerow(["Title", "Year", "IMDb Rating", "Plot", "Actors", "Poster URL"])

                for movie in movies:
                    movie_response = requests.get(
                        f"http://www.omdbapi.com/?i={movie['imdbID']}&apikey={omdb_api_key}")
                    movie_data = movie_response.json()

                    csv_writer.writerow([
                        movie_data.get("Title", ""),
                        movie_data.get("Year", ""),
                        movie_data.get("imdbRating", ""),
                        movie_data.get("Plot", ""),
                        movie_data.get("Actors", ""),
                        movie_data.get("Poster", "")
                    ])

            with open(csv_filename, "rb") as document:
                bot.send_document(message.chat.id, document)
            os.remove(csv_filename)  # Remove the temporary CSV file
        else:
            bot.reply_to(message, "No movies found to export.")
    else:
        bot.reply_to(
            message, "Sorry, something went wrong while fetching movie information.")


@bot.message_handler(func=lambda message: botRunning)
def default(message):
    bot.reply_to(message, 'I did not understand ' + '\N{confused face}')


bot.infinity_polling()