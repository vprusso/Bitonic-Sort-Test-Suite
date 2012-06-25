/*
NewBitonic.h:
	Class for new bitonic sort algorithm.
*/

#ifndef NEW_BITONIC
#define NEW_BITONIC

#include "Sorter.h"

/*New bitonic sort method.*/
class NewBitonic: Sorter{

public:
	void SortAscending(vector<int>& nums, int length);
	void SortDescending(vector<int>& nums, int length);
	void BitonicSortSimplified(int low, int extendedLength, int actualLength, bool direction);
	void BitonicFinalMerge(int low, int extendedLength, int actualLength, bool direction, bool gap);
	
	/*Virtual methods from Sorter.*/
	void BitonicSort(int low, int extendedLength, int actualLength, bool direction);
	void BitonicSortMerge(int low, int extendedLength, int actualLength, bool direction);

private:
	static const bool ascending = true;
	static const bool descending = false;
	bool bottomDirection;
	bool topDirection;
	int nextBiggestPowerTwo;
	int nextSmallestPowerTwo;
};

#endif