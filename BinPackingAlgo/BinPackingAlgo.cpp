#include <iostream>
using namespace std;
double *BestFit;//points the container which is most filled (in bestfilled algorithm)
class BinPackingAlgo {

private: BinPackingAlgo *right = NULL;
	     BinPackingAlgo *left = NULL;
		 
		 double ContainerCap = 0;

public:     
		 int NumberOfBins =1;
		 BinPackingAlgo() {this->ContainerCap = 0; }
		 void SetContainerCapacity(double BinWeight) {this->ContainerCap += BinWeight;}
		 int CapacityReturn() {return this->ContainerCap; }

		 bool FirstFitSearch(BinPackingAlgo *CurrentCap, double BinWeight) {
			 if (CurrentCap != NULL)  {	
					if (CurrentCap->CapacityReturn() + BinWeight <= 1000) {
						 CurrentCap->SetContainerCapacity(BinWeight);
						 return 1; }

				 FirstFitSearch(CurrentCap->left, BinWeight); //traversal, surf between nodes
				 FirstFitSearch(CurrentCap->right, BinWeight); }
			 
			 else { return 0; } };

		 
		 void NodeInsertFirst(BinPackingAlgo *CurrentCap, double BinWeight); //func prototype
		 void NodeInsertBest(BinPackingAlgo *CurrentCap, double BinWeight);
		

		 bool BestFitSearch(BinPackingAlgo *CurrentCap, double BinRemain, double BinWeight) {

			 if (CurrentCap != NULL) {
				 BinRemain = 1000 - CurrentCap->CapacityReturn();//1000-containercap
				 if (BinWeight <= BinRemain) {
					 BestFit = &CurrentCap->ContainerCap; }

				 BestFitSearch(CurrentCap->left, BinRemain, BinWeight);
				 BestFitSearch(CurrentCap->right, BinRemain, BinWeight);

				 if (BestFit != NULL && BinWeight < *BestFit+1) {
					 *BestFit += BinWeight;
					 return 1; }	 
			 }
			 return 0;
		 }
}; //class ended

void BinPackingAlgo::NodeInsertFirst(BinPackingAlgo *CurrentCap, double BinWeight) {
		if ((FirstFitSearch(CurrentCap, BinWeight) == 0)) {
			if (BinWeight < CurrentCap->CapacityReturn() && CurrentCap->left == NULL) {//As long as BinWeight is less than CurrentCap and if the left node is empty.
				CurrentCap->left = new BinPackingAlgo;//Creating memory space for BinPackingAlgo in the ram.  
				CurrentCap->left->SetContainerCapacity(BinWeight);//We are inserting the garbage we have inside to the container on the left. 
				NumberOfBins++;//We are incramenting the number of bins.
				return; }

			if (BinWeight >= CurrentCap->CapacityReturn() && CurrentCap->right == NULL) {
				CurrentCap->right = new BinPackingAlgo;
				CurrentCap->right->SetContainerCapacity(BinWeight);
				NumberOfBins++;
				return; }

			if (BinWeight < CurrentCap->CapacityReturn() && CurrentCap->left != NULL) //If the Container on the left is not NULL insert CurrentCap to the left node. 
				NodeInsertFirst(CurrentCap->left, BinWeight);

			if (BinWeight >= CurrentCap->CapacityReturn() && CurrentCap->right != NULL)  // If the Container on the right is not NULL insert CurrentCap to the right node.
				NodeInsertFirst(CurrentCap->right, BinWeight);		
		}
}

void BinPackingAlgo::NodeInsertBest(BinPackingAlgo *CurrentCap, double BinWeight) {//This insertion function is basically the same with above. 
		if ((BestFitSearch(CurrentCap, 0 ,BinWeight) == 0)) {                      //But instead we use it for BestFit..
			if (BinWeight < CurrentCap->CapacityReturn() && CurrentCap->left == NULL) { //As long as CurrentCapis less than BinWeight and If the container on the left is NULL insert CurrentCap.
				CurrentCap->left = new BinPackingAlgo;//Creating memory space for BinPackingAlgo in the ram. 
				CurrentCap->left->SetContainerCapacity(BinWeight);//We are inseting the garbage we have inside to the container on the left.
				NumberOfBins++;//We are incramenting the number of bins.
				return;}

			if (BinWeight >= CurrentCap->CapacityReturn() && CurrentCap->right == NULL) {
				CurrentCap->right = new BinPackingAlgo;
				CurrentCap->right->SetContainerCapacity(BinWeight);
				NumberOfBins++;
				return;}

			if (BinWeight < CurrentCap->ContainerCap && CurrentCap->left != NULL) //If the Container on the left is not NULL insert CurrentCap to the left node. 
				NodeInsertBest(CurrentCap->left, BinWeight);

			if (BinWeight >= CurrentCap->CapacityReturn() && CurrentCap->right != NULL) // If the Container on the right is not NULL insert CurrentCap to the right node.
				NodeInsertBest(CurrentCap->right, BinWeight);	
		}
}
