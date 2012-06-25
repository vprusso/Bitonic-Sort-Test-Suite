/*
RadixSort.h:
Class for radix sort algorithm
*/
#ifndef RADIX_SORT
#define RADIX_SORT

#include "Sorter.h"

// Radix sort comparator for 32-bit two's complement integers
class RadixSort {

public:
	void PutInQueues(queue<int> q[],  int qcount, vector<int> &data, int digit);
	void GetPartialSorted(queue<int> q[], int qcount, vector<int> &data);
	void RadixSortAlg(vector<int> &data);
	int	GetDigitAt(int n, int digit);
	int FindMaxDigits(vector<int> &data);
	int NumDigits(int n);
};


#endif