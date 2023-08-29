# Cinebot: Your Movie Watchlist Telegram Assistant

## Introduction

Welcome to the Cinebot project! This Telegram bot was designed to help John, a passionate movie lover, organize his movie watchlist effortlessly. With a tendency to forget movies, John can now rely on Cinebot to keep track of movie titles, release years, and IMDb ratings for him.

## Preview
![Cinebot gif](Cine.gif)

## Approach

To craft the Cinebot and realize its functionalities, the following steps were undertaken:

## Step 1: Bot Creation

### 1.1 Botfather Setup

The bot was created on Telegram via Botfather, which provided the crucial API token essential for interaction.

## Step 2: OMDb API Integration

### 2.1 API Key Generation

An API key was generated on the OMDb API platform, allowing Cinebot to request movie data with ease.

### 2.2 API Calls

Utilizing Python, Cinebot constructed API queries like `api_url = f"http://www.omdbapi.com/?apikey={YOUR_KEY}&t={MOVIE_NAME}"` to retrieve movie specifics.

## Step 3: PyTelegramBotAPI Implementation

### 3.1 Library Installation

The `PyTelegramBotAPI` library was installed, enabling seamless interaction with Telegram's Bot API.

## Step 4: Data Management

### 4.1 CSV Storage

Python's file handling capabilities were harnessed to store movie details in a CSV file, guaranteeing data preservation.

## Step 5: Bot Execution and Testing

### 5.1 Bot Deployment

The Cinebot script was executed, bringing the bot to life.

### 5.2 Thorough Testing

A series of tests were performed, ensuring Cinebot could gracefully handle various user inputs and commands.

## GIF Demonstration

To see Cinebot in action, check out the GIF provided at the start of this README.

## Getting Started

To set up your own Cinebot instance, follow these steps:

1. Clone the repository
2. Install necessary dependencies: `pip install pytelegrambotapi requests`
3. Obtain an OMDb API key and replace `YOUR_KEY` in the code.
4. Execute the bot script: `Cine.py`
5. Initiate a chat with your bot on Telegram and start crafting your movie watchlist!

## Acknowledgments

I extend my gratitude to the following:

- [PyTelegramBotAPI](https://github.com/eternnoir/pyTelegramBotAPI) for streamlining Telegram bot creation.
- [OMDb API](https://www.omdbapi.com/) for their invaluable movie data API.

---
*Note: This task was completed as part of my learning journey with Technity Tech and is not intended for commercial purposes.*
