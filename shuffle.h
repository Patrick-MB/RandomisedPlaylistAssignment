//------------------------------------------
// Created by Patrick Mbanusi on 26/03/2021.
//-------------------------------------------

#ifndef SEP_ASSIGNMENT1_SHUFFLE_H
#define SEP_ASSIGNMENT1_SHUFFLE_H
#include "sort.h"
#include "input.h"
#define MAX_NUM 200

// max number of songs by each artiste allowed in playlist
#define MAX_SONGS_BY_ARTISTE 3
// max time of playlist; 60 minutes = 3600 seconds
#define MAX_TIME 3600
// max artistes in playlist
#define MAX_LEN 5
// call all necessary function prototypes
void generatePlaylist(char ast[MAX_SONGS][MAX_INFO_LENGTH], int numSongs);
void inside_outShuffle(int shuffled[MAX_SONGS], int numSongs);
void convertToMins_Secs(int numSeconds);
int count(char* currArtiste, char allArtistes[MAX_NUM][MAX_NUM], int n);

#endif //SEP_ASSIGNMENT1_SHUFFLE_H
