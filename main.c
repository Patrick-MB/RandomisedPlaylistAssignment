//-------------------------------------------
// Created by Patrick Mbanusi on 26/03/2021.
//-------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "shuffle.h"

int main(int argc, char* argv[])
{
    FILE *fp;
    char artiste_song_time[MAX_SONGS][MAX_INFO_LENGTH];
    int numSongs;
// Check if we have an argument.
    if (argc > 1)
    {
        if ((fp = fopen(argv[1], "r")) == NULL)
        {
            printf("%s does not exist or cannot be opened for reading.\n", argv[1]);
            return 1;
        } else {
            numSongs = readFile(fp, artiste_song_time);
            fclose(fp);
        }
    } else {
        // No file supplied; try the default.
        if ((fp = fopen(DEFAULT_INPUT_FILE, "r")) == NULL) {
            // Default file isn't there. Enter from the keyboard.
            printf("%s: No file found.\n", DEFAULT_INPUT_FILE);
            printf("Enter from the keyboard.\n");
            numSongs = readKeyboard(artiste_song_time);
            fclose(fp);
        } else {
            numSongs = readFile(fp, artiste_song_time);
            fclose(fp);
        }
    }

// Sort the artistes and songs
    insertion_sort(artiste_song_time, numSongs);
    // before continuing, copy artiste_song_time array of strings to another array of strings(astCopy)
    // as this allows both print_artistes_songs_times and generatePlaylist functions to run
    // simultaneously (a clash is caused by the use of the strtok function in both)
    char astCopy[MAX_SONGS][MAX_INFO_LENGTH];
    for (int k = 0; k < numSongs; k++) {
        strcpy(astCopy[k], artiste_song_time[k]);
    }
// ... print out the sorted artistes and songs
    print_artistes_songs_times(artiste_song_time, numSongs);
    printf("\n");
// ... and generate and print out the playlist.
    // seed for random input
    srand(time(NULL));
    generatePlaylist(astCopy, numSongs);

    return 0;
}
