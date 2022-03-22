//-------------------------------------------
// Created by Patrick Mbanusi on 26/03/2021.
//-------------------------------------------

#ifndef SEP_ASSIGNMENT1_INPUT_H
#define SEP_ASSIGNMENT1_INPUT_H

#include <stdio.h>
// max characters for names
#define MAX_CHAR 100
// max number of songs
#define MAX_SONGS 50
// max length of the artistes songs info
#define MAX_INFO_LENGTH 100
// default input file = artistes+songs.txt (used to prevent hard coding)
#define DEFAULT_INPUT_FILE "alternateSongs.txt"

// call all relevant file prototypes
int readFile(FILE* fp, char ast[MAX_SONGS][MAX_INFO_LENGTH]);
int readKeyboard(char ast[MAX_SONGS][MAX_INFO_LENGTH]);

#endif //SEP_ASSIGNMENT1_INPUT_H
