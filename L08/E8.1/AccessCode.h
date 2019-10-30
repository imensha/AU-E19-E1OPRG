#pragma once

#include <time.h>
#include <stdlib.h>

#define CODE_SIZE 8
#define CODE_BUFFER (CODE_SIZE + 1)

void createCode( char [] );
int checkCode( char validCode[], char inputCode[] );
int changeCode( char validCode[] );