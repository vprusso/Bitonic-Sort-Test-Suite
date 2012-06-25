/*
Sorter.cpp:
	Class implementation of primary sorting base class.
*/
#include "Sorter.h"

/*Obtains closest greater power of 2.*/
int Sorter::GetNextBiggestPowerTwo(int value){

	//Uses SWAR method of bit rolling up.
	if(value < 0x7fffffff){
		value |= (value >> 1);
		value |= (value  >> 2);
		value |= (value  >> 4);
		value |= (value  >> 8);
		value |= (value  >> 16);
		return (value + 1);
	}//end if

	//Failure.
	else
		return -1;
}

/*Obtains closest lesser power of 2.*/
int Sorter::GetNextSmallestPowerTwo(int value){
		
	//Uses SWAR method of bit rolling up.
	if(value < 0x7fffffff){
		value |= (value  >> 1);
		value |= (value  >> 2);
		value |= (value  >> 4);
		value |= (value  >> 8);
		value |= (value  >> 16);
		return ((value>>1)+1);
	}//end if

	//Failure.
	else
		return -1;
}

/*Checks if number is a power of two (uses some bit twidling)*/
bool Sorter::isPowerTwo(int value){return (value & (value - 1)) == 0;}

/**/
void Sorter::Exchange(int i, int j){

	int temp = numList[i];
	numList[i] = numList[j];
	numList[j] = temp;
}

/**/
void Sorter::Compare(int i, int j, int actualLength, bool direction){

	if (!(actualLength-1 < i || actualLength-1 < j))
		if (direction == (numList[i] > numList[j]))
			Exchange(i,j);
}

/**/
void Sorter::Flip(int low, int actualLength){

	int temp;

	//Middle element doesn't get flipped if it exists.
	int halfActualLen = actualLength / 2;

	for (int i = 0; i < halfActualLen; i++){
		temp = numList[low+i];
		numList[low+i] = numList[low+actualLength-i-1];
		numList[low+actualLength-i-1] = temp;
	}//end for
	
	//Note, this isn't the "real" position of array for top elements
	//Array has been virtually offset by actuallength-NextSmallestPowerOf2
}

/**/
void Sorter::BitonicSort(int low, int extendedLength, int actualLength, bool direction){
}

/**/
void Sorter::BitonicSortMerge(int low, int extendedLength, int actualLength, bool direction){
}

void Sorter::Print(vector<int> const & data){
    vector<int>::const_iterator iter = data.begin();

    for (; iter != data.end(); ++iter)
        cout << *iter << " ";
    

    if (data.size() > 0)
        cout << endl;
    
}

/*Destructor*/
Sorter::~Sorter(){
}

