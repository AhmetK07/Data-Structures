#include "BinPackingAlgo.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
	int input;
	cout << "	----|  WELCOME TO FIRST AND BEST FIT GARBAGE PROGRAM |----	" << endl << endl << "How do you want to continue the process?" << endl << endl;
	cout << "1: txt file" << endl << "2: random generated" << endl << endl <<"Answer? : "; cin >> input;
	
	if (input==1){
		int BinWeight[1000]; //Our array of BinsWeights.
		int IncomingGarbage = 0;int temp;
		BinPackingAlgo FirstFitAlgo; // Objects for the class.
		BinPackingAlgo BestFitAlgo;
		string MyNumber; fstream MyReadFile("data.txt");
		/*-------------------------------------------------------------------------------------------*/
		while (getline (MyReadFile,MyNumber)){  //Our line for reading text.
			stringstream CurrentGarbage(MyNumber);	//variable type conversion.
			temp = 0;
			CurrentGarbage >> temp;
			BinWeight[IncomingGarbage] = temp; IncomingGarbage++; }
		/*-------------------------------------------------------------------------------------------*/
		int TotalGarbage = 0;
		for (int j = 0; j < IncomingGarbage; j++){
			TotalGarbage = TotalGarbage + BinWeight[j];
			FirstFitAlgo.NodeInsertFirst(&FirstFitAlgo, BinWeight[j]); //Insertion using algorithms.
			BestFitAlgo.NodeInsertBest(&BestFitAlgo, BinWeight[j]); }
		/*-------------------------------------------------------------------------------------------*/
		cout << "Incoming Garbage Number	:" << IncomingGarbage << " pieces.	|   Best Fit	: " << BestFitAlgo.NumberOfBins << endl;
		cout << "Total Bin Weight	:" << TotalGarbage / 1000 << " kg.	|   First Fit	: " << FirstFitAlgo.NumberOfBins << endl;

	}

	if (input==2){srand(time(NULL)); // for random number generation
		BinPackingAlgo FirstFitAlgo; //Objects for class.
		BinPackingAlgo BestFitAlgo;
		/*-------------------------------------------------------------------------------------------*/
		int TotalGarbage = 0;
		int IncomingGarbage = rand() % 1000 + 1, *BinWeight = new int[IncomingGarbage];	 //memory allocation.
		for (int i = 0; i < IncomingGarbage; i++) {
			BinWeight[i] = rand() % 1000 + 0; TotalGarbage += BinWeight[i];
			FirstFitAlgo.NodeInsertFirst(&FirstFitAlgo, BinWeight[i]); //algorithm 
			BestFitAlgo.NodeInsertBest(&BestFitAlgo, BinWeight[i]); /*algorithm */   }
		/*-------------------------------------------------------------------------------------------*/
		cout << "Incoming Garbage Number	:" << IncomingGarbage << " pieces.	|   Best Fit	: " << BestFitAlgo.NumberOfBins << endl;
		cout << "Total Bin Weight	:" << TotalGarbage / 1000 << " kg.	|   First Fit	: " << FirstFitAlgo.NumberOfBins << endl;
	}


	if (input!=1 && input!=2){
		cout << "WRONG NUMBER";
	}



}