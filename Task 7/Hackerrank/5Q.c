#include <stdio.h>
#include <string.h>

void timeConversion(char* s, char* military_time) {
    int hh, mm, ss;
    char meridiem[3];

    sscanf(s, "%d:%d:%d%s", &hh, &mm, &ss, meridiem);

    if (strcmp(meridiem, "PM") == 0 && hh != 12) {
        hh += 12;
    } else if (strcmp(meridiem, "AM") == 0 && hh == 12) {
        hh = 0;
    }

    sprintf(military_time, "%02d:%02d:%02d", hh, mm, ss);
}

int main() {
    char time_12_hour[11];
    char military_time[9];

    scanf("%s", time_12_hour);

    timeConversion(time_12_hour, military_time);

    printf("%s\n", military_time);

    return 0;
}
