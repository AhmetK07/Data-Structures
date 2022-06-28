#ifndef BINPACKINGALGO_H
#define BINPACKINGALGO_H

class BinPackingAlgo 
{

private:

	BinPackingAlgo *right;
    BinPackingAlgo *left;
	double ContainerCap = 0;
public:
	BinPackingAlgo();
	int NumberOfBins;
	bool FirstFitSearch(BinPackingAlgo *CurrentCap, double BinWeight);
	void NodeInsertFirst(BinPackingAlgo *CurrentCap, double BinWeight);
	void NodeInsertBest(BinPackingAlgo *CurrentCap, double BinWeight);
	void SetContainerCapacity(double BinWeight); int CapacityReturn();
	bool BestFitSearch(BinPackingAlgo *CurrentCap, double BinRemain, double BinWeight);
	
};
#endif // 
