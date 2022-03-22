//-------------------------------------------
// Created by Patrick Mbanusi on 26/03/2021.
//-------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
// function to sort ast array of strings. Uses Insertion sort.
void insertion_sort(char ast[MAX_SONGS][MAX_INFO_LENGTH], int numSongs)
{
    // call variables
    int i,j;
    char temp[MAX_INFO_LENGTH];
    // loop through array and lexicographically sort it
    for(i=0; i<=numSongs; i++)
    {
        for(j=i+1; j <=numSongs; j++)
        {
            if(strcmp(ast[i], ast[j]) > 0)
            {
                strcpy(temp, ast[i]);
                strcpy(ast[i], ast[j]);
                strcpy(ast[j], temp);
            }
        }
    }
}
// function to print sorted artistes and their songs
void print_artistes_songs_times(char ast[MAX_SONGS][MAX_INFO_LENGTH], int numSongs)
{
    printf("Sorted list of artistes and songs\n");
    // create variables to print out sorted list of songs
    // initialise the prevArtiste, song name and song duration and print
    // out the first line of array(element)
    char* prevArtiste = strtok(ast[0], "*");
    printf("%s\n", prevArtiste );
    char* songName = strtok(NULL, "*");
    char* songDuration = strtok(NULL, "*");
    printf("  o %s***%s\n", songName, songDuration);

    for (int i = 1; i < numSongs; ++i)
    {
        // use strtok to seperate and save the current artiste, next song name and length
        char* currArtiste = strtok(ast[i], "*");
        songName = strtok(NULL, "*");
        songDuration = strtok(NULL, "*");
        // check if the currArtiste is the same as the prevArtiste, if it isn't
        // update the prev artiste to the curr one, print a blank line and print their name.
        if (strcmp(currArtiste, prevArtiste) != 0 )
        {
            strcpy(prevArtiste, currArtiste);
            printf("\n");
            printf("%s\n", currArtiste);
        }
        // print all that artistes songs and song lengths
        printf("  o %s***%s\n", songName, songDuration);
    }
}