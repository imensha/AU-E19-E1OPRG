#include <stdio.h>
#include <string.h>
#include "AccessCode.h"

void createCode( char codeAlias[] )
{
	int ascii;

	srand( time(0) );

	for( size_t index=0; index<CODE_SIZE; index++ )
	{
		ascii =  (rand()%75 + 48);

		// if ascii number is NOT a letter or digit (check ASCII table)
		if( 57<ascii && ascii<65 || 90<ascii && ascii<97 )
			index--;
		else
			codeAlias[ index ] = ascii;
	}

	codeAlias[ CODE_SIZE ] = '\0';
}

int checkCode( char correctCodeAlias[], char codeToCheckAlias[] )
{
    //if (strlen(correctCodeAlias) != strlen(codeToCheckAlias))
    //    return 0;

    int compareResult = strncmp(correctCodeAlias, codeToCheckAlias, CODE_BUFFER);

    return compareResult == 0 ? 1 : 0;
}

int changeCode( char currentCodeAlias[] )
{
    char inputCurrentCode[CODE_BUFFER];
    char inputNewCode[CODE_BUFFER], inputNewCodeConfirm[CODE_BUFFER];

    printf_s("Enter current code: ");
    scanf_s("%8s", inputCurrentCode, CODE_BUFFER);

    // Compare current code with the input code
    int compareCurrent = strcmp(currentCodeAlias, inputCurrentCode);

    // Code is invalid
    if (compareCurrent != 0)
    {
        return 0;
    }

    // Get the new code from user
    printf_s("Enter new code: ");
    scanf_s("%8s", inputNewCode, CODE_BUFFER);
    // Get the new code from user again to confirm
    printf_s("Enter new code: ");
    scanf_s("%8s", inputNewCodeConfirm, CODE_BUFFER);

    int compareNew = strcmp(inputNewCode, inputNewCodeConfirm);

    // New codes match and current code should be updated
    if (compareNew == 0)
    {
        strncpy(currentCodeAlias, inputNewCode, CODE_BUFFER);
        return 1;
    }
    // New codes did not match and current code should not be updated
    else
    {
        return 0;
    }
}
