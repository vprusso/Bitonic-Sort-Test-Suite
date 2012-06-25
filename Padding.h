/*
Padding.h:
	Class for spatial padding bitonic sort algorithm.
*/
#ifndef PADDING
#define PADDING

#include "Sorter.h"

class Padding : Sorter{
public:
	vector<int> BitonicSort(vector<int>& nums, bool up);
	vector<int> BitonicMerge(vector<int>& nums, bool up);
	vector<int> BitonicCompare(vector<int>& nums, bool up);

private:
	vector<int> numList;
	bool up;

};

#endif 