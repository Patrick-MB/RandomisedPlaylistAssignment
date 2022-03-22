//--------------------------------------------
// Created by Patrick Mbanusi on 26/03/2021.
//-------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shuffle.h"
// function to generate random playlist
void generatePlaylist(char ast[MAX_SONGS][MAX_INFO_LENGTH], int numSongs)
{
    // array of shuffled index for playlist
    int shuffled[numSongs];
    // Initialise shuffled array containing indexing of size numSongs
    for (int i = 0; i < numSongs; i++) {
        shuffled[i] = i;
    }
    // send shuffled to the inside_outShuffle
    inside_outShuffle(shuffled, numSongs);

    printf("Randomised playlist\n");
    // to track total time accumulated by the random songs in the playlist
    int i = 0, n = 0;
    int totalTime = 0;
    // initialise previous artiste, song name and song duration
    char* prevArtiste = strtok(ast[shuffled[i]], "*");
    char* songName = strtok(NULL, "*");
    char* songDuration = strtok(NULL, "*");
    // var to hold each song duration as a string (max of 4 characters e.g 11:09)
    char songD[MAX_LEN];
    // array of artiste names to check how many times an artiste has appeared
    char allArtistes[MAX_NUM][MAX_NUM];
    // pointer for currArtiste
    printf("%s: \"%s\" (%s)\n", prevArtiste, songName, songDuration);
    // Variables for song duration:
    // to hold the string minutes and seconds (to then be converted to their integer equivalents)
    char* strMin;
    char* strSec;
    // to hold song duration as integer equivalents
    int minutes;
    int seconds;
    // to hold the converted song length in seconds
    int songInSeconds;
    // increment i, and initialise currArtiste pointer and penultArtiste
    i = 1;
    char* currArtiste = strtok(ast[shuffled[i]], "*");
    char* penultArtiste = strtok(ast[shuffled[0]], "*");

    while (i < numSongs && totalTime < MAX_TIME)
    {
        // update prevArtiste (to current) and penultArtiste (to previous)
        strcpy(penultArtiste, prevArtiste);
        strcpy(prevArtiste, currArtiste);
        // get current artiste
        currArtiste = strtok(ast[shuffled[i]], "*");
        // add current artiste to array holding all artistes' names
        strcpy(allArtistes[n], currArtiste);
        n++;
        //check if an artiste occurs 3 times in a row
        if (strcmp(currArtiste, prevArtiste) != 0  && strcmp(currArtiste, penultArtiste) != 0) {
            // check artiste has not appeared more than 3 times
            if (count(currArtiste, allArtistes, n) < MAX_SONGS_BY_ARTISTE)
            {
                // get song title and song duration
                songName = strtok(NULL, "*");
                songDuration = strtok(NULL, "*");
                // songD will hold the duration of song as string before it is altered and turned into seconds
                strncpy(songD, songDuration, 5);
                strMin = strtok(songDuration, ":");
                strSec = strtok(NULL, ":");
                // convert string time to integer equivalent
                minutes = atoi(strMin);
                seconds = atoi(strSec);
                // multiply minutes by 60 to turn into seconds
                minutes = minutes*60;
                // add minutes and seconds together
                songInSeconds = (minutes + seconds);
                // add this song's duration to totalTime
                totalTime += songInSeconds;
                // print out artistes and songs each loop
                printf("%s: \"%s\" (%s)\n", currArtiste, songName, songD);
            }
        }
        i++;
    }
    // convert total time to minutes and seconds
    convertToMins_Secs(totalTime);
}
// function to shuffle indexing for random playlist. Using Knuth inside-out shuffle.
void inside_outShuffle(int shuffled[MAX_SONGS], int numSongs)
{
    int arr[numSongs];
    int i, j;
    // initialise array
    for (i = 0; i < numSongs; i++) {
        arr[i] = i;
    }
    // loop to shuffle array indexing
    for (i = 0; i < numSongs - 1; i++)
    {
        // generate a random number `j` such that `0 <= j <= i`
        j = rand() % (i + 1);
        if (j != i)
        {
            arr[i] = arr[j];
            arr[j] = shuffled[i];
        }
    }
    // put jumbled arr into shuffled
    for (int k = 0; k < numSongs; k++) {
        shuffled[k] = arr[k];
    }
}
// function to convert totalTime(seconds) to minutes and seconds
void convertToMins_Secs(int numSeconds)
{
    // call variables
    int seconds;
    int minutes;
    // change to seconds and minutes
    seconds = numSeconds % 60;
    minutes = numSeconds / 60;
    // print result
    printf("Total Duration: %d:%d.", minutes, seconds);
}
// function to count the amount of times an artiste has appeared in playlist
int count(char* currArtiste, char allArtistes[MAX_NUM][MAX_NUM], int n)
{
    // c(count) will hold how many times an artiste has appeared
    int c = 0;
    int i;
    // n is how many artistes are generated
    // loop to count how many times artiste has appeared
    for (i = 0; i < n; i++) {
        if (strcmp(allArtistes[i], currArtiste) == 0) {
            c = c + 1;
        }
    }
    // return count of artiste
    return c;
}