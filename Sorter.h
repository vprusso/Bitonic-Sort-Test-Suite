/*
Sorter.h:
	Base class for sorting algorithms.
*/

#ifndef SORTER
#define SORTER

#include "Resources.h"

using namespace std;

/*Primary sort class. Consists of functions common to all sorts.*/
class Sorter{

public:
	int GetNextBiggestPowerTwo(int value);
	int GetNextSmallestPowerTwo(int value);
	bool isPowerTwo(int value);

	void Exchange(int i, int j);
	void Compare(int i, int j, int actualLength, bool direction);
	void Flip(int low, int actualLength);
	
	//Print out contents of vector.
	void Print(vector<int> const & data);

	virtual void BitonicSortMerge(int low, int extendedLength, int actualLength, bool direction);
	virtual void BitonicSort(int low, int extendedLength, int actualLength, bool direction);
	virtual ~Sorter();
	
protected:
	vector<int> numList;	
};

#endif 