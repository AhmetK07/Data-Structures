#include "TermHeader.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(void) 
{

	BullsNCows new_BullsNCows = {.index = 1 };   

	FILE *history; //We are defining the file pointer beacuse there is an interaction between this when we use fopen() function.

	int DigCount = 0; // A value that stores our digitcount.

	char UserGuess[75];  // Declaring UserGuess as a chararray to store the users guess.

	char newsecrand[25];  // At the end we copy the string that leads to the pointer.

	char Answr[3];   // We are assigning a char array which stores yes / no when user is asked after playing the game.

	srand(time(NULL));  // This is to get a random number.

	int x = 0;

	ConstantLoop

	{
	
	START:

		printf("***Welcome to the Bulls & Cows Game***\n"); 

		printf("\n");

		printf("Enter the digit count that you desire:");

		scanf("%d", &DigCount);

		int bulls;

		int cows;

		int Rndm[100]; // A Rndm array beacuse we need a array to store random number.

		char *Scnd_rand = malloc(sizeof(char)* DigCount);  // Opens a room for pointer

		for (int i = 0; i < DigCount; i++)
		{

		LOOP:
			Rndm[i] = rand() % 9 + 0;   //Picks a random number between 0 and 9 using Rndm array and rand() function.
			
			

			if (Rndm[0] == 0)

			{
				Deliver LOOP;      //If the Rndms first digit is 0 that means the number is not generated with the correct digit so it creates a number again.
			}


			if (i > 1)

			{
				int h = 0;
				while (Rndm[h] < 10 && Rndm[h] > -1)   //As long as the digit is under 10 and its greater than the value of -1 it gets in to this while loop.

				{

					if (h == i)		// Checks the array if the characters are equal or not if all characters are checked it beaks from the statement. 

					{
						break;
					}

					if (Rndm[h] == Rndm[i]) // Checks if there is a requirsion between numbers it there is a reqursion it goes to loop and picks another number again.   

					{
						Deliver LOOP;

					}

					h++;
				}
			}


			if (i != 0)  // This part compares the first digit and the second digit.

			{
				if (Rndm[i - 1] == Rndm[i])

				{
					Deliver LOOP;  //If the numbers are equal it goes to reseting again.
				}

			}
		}

		for (int i = DigCount; i < 101; i++)  // Resets the remainder of the unnecesary Digits that user doesn't write on the  setting part.

		{

			Rndm[i] = Rndm[i + 1];

		}
 

		

		printf("\n");

		printf("Okay,I have chosen the number."); 

		printf("\n");


		ConstantLoop

		{

			int i = 0;

		REPEAT:

			printf("What's your UserGuess:");

			scanf("%s", UserGuess);  //Gets users input as a string.

			Scnd_rand = IntCon(Rndm, DigCount);  //Uses IntCon function to concatanate the Rndm value and DigCount into a Scnd_rand value. 

			new_BullsNCows.AttemptCount++;  //Updating the attempt count to the structure.

			strcpy(newsecrand, Scnd_rand);  // copys the Scnd_rand to nesecrand

			new_BullsNCows.NumSec = atoi(newsecrand);  // atoi changes string into int

			printf("\n");

			if (new_BullsNCows.AttemptCount == 10 || UserGuess[0] == 'q')  //If users guess contains q in the first slot in UserGuess or the attempt count is up to 10 you lose the game.

			{

				new_BullsNCows.result = 0;  //Updates the result as a lose in our structure.

				printf("you LOST!");

				printf("\n");

				printf("Do you want to play one more time (yes/no):");

				scanf("%s", Answr);  //Gives a chance for users to play another round.

				printf("\n");




				if (Answr[0] == 'y')  //Cheks if the users want to keep playing by looking at the first slot of Answr if its a yes.

				{
					new_BullsNCows.index++;  //Updates the amount of played rounds in our structure.

					Deliver WRITE;				//Goes down to the writing part which stores our structures data and writes them into a txt file.
				}

				else

				{
					Deliver WRITE;  //This time user has chosen to quit the game and one again they are sent to writing.
				}

			}

			if (strlen(UserGuess) > DigCount || strlen(UserGuess) < DigCount)    //Checks if the user is giving the program appropriate amount of Digits by using strlen() function.

			{
				printf("UserGuess must have lenght of %d,try again", DigCount);

				printf("\n");  

				Deliver REPEAT;  //Goes to the section that gets users guess once again.
			}

			if (CharacterCh(UserGuess) == 0)  //Checks whether or not the input contains numbers or not.

			{
				printf("Contains non-numbers,try again");

				printf("\n");

				Deliver REPEAT;  //Once again goes to get the users input again.
			}

			new_BullsNCows.UserGuess_list[i] = atoi(UserGuess);  //GuessList beacomes Int.

			i++;


			IfComp(UserGuess, newsecrand, &bulls, &cows, DigCount);  //Compares the variables and then calculates the bulls and cows 

			printf("bulls:%d cows:%d \n", bulls, cows);  //Users are getting a feedback related with their guess.

			if (bulls == DigCount)  //Looks if the bulls are equal if yes basically you have won.

			{
				new_BullsNCows.result = 1; //Updates the result as a win.

				printf("You won!");
				
				printf("\n");

				printf("Do you want to play one more time (yes/no):"); //Gives a chance to play the game one more round once again.

				scanf("%s", Answr); //Gets the answer.

				printf("\n");

				if (Answr[0] == 'y') //If the answer is yes

				{
					new_BullsNCows.index++;  //It updates the sturcture for amount of played rounds.

					Deliver WRITE;  //Once again we are sent to the writing part which stores our structure by priting our data onto it.
				}

				else if (Answr[0] == 'n')  //If the answer is no

				{
					Deliver WRITE;  //We are sent to writing likewise.
				}
			}

			else  //If the bulls or not equal

			{
				Deliver REPEAT; // You are sent to guessing part.
			}


		}



	WRITE:

		if (history = fopen("history.txt", "r"))  //If it there is a file named history.txt opens the "reading" mode. 

		{
			fclose(history);  //It closes history reading mode.

			history = fopen("history.txt", "a");  //And it opens in the file in a "append" mode. 
		}


		else

		{
			history = fopen("history.txt", "w");  //Otherwise it creates the file and opens in writing mode. 
		}


		while (x < new_BullsNCows.index)  //As long as the updated round played by a user is greater than the starting point. 

		{
			int v = 0;

			fprintf(history, "%d- ", x + 1);  // It writes the line count.

			fprintf(history, "%d ", new_BullsNCows.NumSec);  //And it writes the secret number.

			do

			{
				fprintf(history, "%d ", new_BullsNCows.UserGuess_list[v]);  

				v++;
			} 
			
			while (v != new_BullsNCows.AttemptCount - 1);  // While attempt count is not equal to none it prints the file users guesslist.

			fprintf(history, "%d ", new_BullsNCows.AttemptCount - 1);  // Prints out to the file attempt count.

			fprintf(history, "%d ", new_BullsNCows.result);  // Prints out the result as winning or losing by 1's and 0's

			fprintf(history, "\n");  

			fclose(history);

			new_BullsNCows.AttemptCount = 0;  // Sets the attempt count to 0 for starting the game once again.

			x++;

			if (Answr[0] == 'y')  // If the Answr is yes 

			{
				Deliver START;  // You are being sent to the starting of the program.
			}
			if (Answr[0] == 'n')  // If the Answr is no 

			{
				exit(0);  // You are exiting the code.
			}


		}


	} 
	
}