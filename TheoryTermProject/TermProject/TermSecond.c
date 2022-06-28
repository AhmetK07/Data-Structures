#include "TermHeader.h"
#include <stdio.h>
#include <string.h>



char extern *IntCon(int arry[], int Dig) // A function for the use of concatanation in case of rand() function creates numbers.

{

	int i = 0;

	int a = 0;

	char String[20];

	for (i = 0; i != Dig; i++)

	{
		a += sprintf(&String[i], "%d", arry[i]);
	}

	String[Dig] = '\0';

	return (char*)String;


}



void extern IfComp(char UserGuess[], char *NumSec,int* bull,int* cow,int Dig) // A function that searches bulls and cows if the requirments are met.
{
	int bulls = 0, cows = 0;

		for (int a = 0; UserGuess[a] != '\0'; a++)
		{
			for (int b = 0; UserGuess[b] != '\0';b++)
			{
				if (b==a && UserGuess[a] == NumSec[b])
				{
					bulls++;
				}
				else if (UserGuess[a] == NumSec[b])
				{
					cows++;
				}
			}
		}

		*bull = bulls;

		*cow = cows;
		
}



int extern CharacterCh(char UserGuess[]) //A function that checks if the users guess contains characters are between 0 and 9.
{
	int i = 0;

	while (UserGuess[i] != '\0')

	{

		if (UserGuess[i] == '9' || UserGuess[i] == '8' || UserGuess[i] == '7' || UserGuess[i] == '6' || UserGuess[i] == '5' || UserGuess[i] == '4' || UserGuess[i] == '3' || UserGuess[i] == '2' || UserGuess[i] == '1' || UserGuess[i] == '0')

		{
			return 1;
		}
		i++;
	}

	return 1;
}