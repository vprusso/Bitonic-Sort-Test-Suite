/*
Padding.h:
Class implementation padding bitonic sort algorithm.
*/

#include "Padding.h"

vector<int> Padding::BitonicSort(vector<int>& nums, bool up){
	if (nums.size() <= 1)
		return nums;

	//First half.
	vector<int> first(nums.begin(), nums.begin() + (nums.size()/2)); 
	first = BitonicSort(first,up);

	//Second half.
	vector<int> second;
	for (unsigned i = nums.size()/2; i < nums.size(); i++)
		second.push_back(nums[i]);
	second = BitonicSort(second,!up);

	//Add first and second vectors.
	first.insert( first.end(), second.begin(), second.end() );

	return BitonicMerge(first, up);
}

vector<int> Padding::BitonicMerge(vector<int>& nums, bool up){

	if (nums.size() == 1)
		return nums;

	else{
		nums = BitonicCompare(nums, up);

		//First half.
		vector<int> first(nums.begin(), nums.begin() + (nums.size()/2)); 
		first = BitonicMerge(first, up);

		//Second half.
		vector<int> second;
		for (unsigned i = nums.size()/2; i < nums.size(); i++)
			second.push_back(nums[i]);
		second = BitonicMerge(second, up);

		//Add first and second vectors.
		first.insert( first.end(), second.begin(), second.end() );
		return first;

	}//end else
}

vector<int> Padding::BitonicCompare(vector<int>& nums, bool up){

	int distance = nums.size() / 2;

	for (int i = 0; i < distance; i++)
		if ((nums[i] > nums[i+distance])==up )
			swap(nums[i], nums[i+distance]);
	
	return nums;
}
