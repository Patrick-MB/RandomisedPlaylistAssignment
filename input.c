//-------------------------------------------
// Created by Patrick Mbanusi on 26/03/2021.
//-------------------------------------------

#include <stdio.h>
#include <string.h>
#include "input.h"

int readFile(FILE* fp, char ast[MAX_SONGS][MAX_INFO_LENGTH])
{
    int numSongs = 0;

    while( !feof(fp) )
    {
        // variables to store artistes info
        char artiste[MAX_INFO_LENGTH];
        char songInfo[MAX_INFO_LENGTH];
        // read in an artistes name
        fgets(artiste, MAX_CHAR, fp);
        // remove trailing new line character
        artiste[strcspn(artiste, "\n")] = 0;
        // read in the song name and song length
        fgets(songInfo, MAX_CHAR, fp);
        songInfo[strcspn(songInfo, "\n")] = 0;
        do {
            // copy artiste name into a_s_t array
            strcpy(ast[numSongs], artiste);
            // append *** to the a_s_t array
            strcat(ast[numSongs], "***");
            // append the song info to the a_s_t array
            strcat(ast[numSongs], songInfo);
            // increment number songs count and i
            numSongs++;
            // read in another line (either another song or a blank line)
            fgets(songInfo, MAX_CHAR, fp);
            songInfo[strcspn(songInfo, "\n")] = 0;
            // keep looping until we reach end of file or songInfo hits a new line i.e next artiste
        } while (strlen(songInfo) > 1 && !feof(fp));
    }
    return numSongs;
}

int readKeyboard(char ast[MAX_SONGS][MAX_INFO_LENGTH]) {
    int numSongs = 0;
    // variables to store artistes info
    char artiste[MAX_INFO_LENGTH];
    char songInfo[MAX_INFO_LENGTH];
    printf("Please enter all artiste's song information using the following format:\n"
           "'Song title'***'Song duration'\n");
    printf("Enter 0 when finished.\n");
    // loop while string length is greater than i.e. not 0
    while (strlen(artiste) > 1 || strlen(songInfo) > 1) {
        // ask user for input
        printf("Enter artiste name: \n");
        fgets(artiste, MAX_INFO_LENGTH, stdin);
        // check if user entered 0
        if (strlen(artiste) == 2) {
            return numSongs;
        }
        // remove trailing new line character
        artiste[strcspn(artiste, "\n")] = 0;
        // ask for song info
        printf("Enter song name and duration: \n");
        fgets(songInfo, MAX_INFO_LENGTH, stdin);
        songInfo[strcspn(songInfo, "\n")] = 0;
        do {
            // copy artiste name into a_s_t array
            strcpy(ast[numSongs], artiste);
            // append *** to the a_s_t array
            strcat(ast[numSongs], "***");
            // append the song info to the a_s_t array
            strcat(ast[numSongs], songInfo);
            // increment number songs count and i
            numSongs++;
            // read in another line
            printf("Enter next song's name and duration:\n");
            fgets(songInfo, MAX_INFO_LENGTH, stdin);
            songInfo[strcspn(songInfo, "\n")] = 0;
            // keep looping until user inputs 0
        } while (strlen(songInfo) != 1);
    }
    return numSongs;
}
