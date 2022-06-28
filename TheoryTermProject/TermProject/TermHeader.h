#ifndef TERMHEADER_H
#define TERMHEADER_H

#define Deliver goto
#define ConstantLoop while(1)

typedef struct bullsandcows //Our structure for esssential functions and operations
{
	int index;

	int	NumSec;

	int	AttemptCount;

	int	result;

	int UserGuess_list[];

}BullsNCows;

void IfComp(char UserGuess[], char NumSec[], int* bulls, int* cows, int Dig);  // A function that searches bulls and cows if the requirments are met.

char* IntCon(int array[], int Dig); // A function for the use of concatanation in case of rand() function creates numbers.

int CharacterCh(char UserGuess[]); //A function that checks if the users guess contains characters are between 0 and 9.


#endif