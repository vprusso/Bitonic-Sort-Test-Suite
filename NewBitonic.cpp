/*
NewBitonic.cpp:
	Class implementation for new bitonic sorting algorithm.
*/

#include "NewBitonic.h"

/*Ascending sort*/
void NewBitonic::SortAscending(vector<int>& nums, int length){
	
	nums = numList;
	nextBiggestPowerTwo = GetNextBiggestPowerTwo(length);
	bottomDirection = ascending;
	topDirection = descending;
	BitonicSortSimplified(0, nextBiggestPowerTwo, length, bottomDirection);
}

/*Descending sort*/
void NewBitonic::SortDescending(vector<int>& nums, int length){

	nums = numList;
	nextBiggestPowerTwo = GetNextBiggestPowerTwo(length);
	bottomDirection = descending;
	topDirection = ascending;
	BitonicSortSimplified(0, nextBiggestPowerTwo, length, bottomDirection);

}

/*Simplified bitonic sort in new bitonic algorithm.*/
void NewBitonic::BitonicSortSimplified(int low, int extendedLength, int actualLength, bool direction){

	if (extendedLength > 1){
		int halfExLen = extendedLength / 2;

		if (bottomDirection == descending){

			if (extendedLength == nextBiggestPowerTwo){
				BitonicSort(low, actualLength - halfExLen, actualLength, topDirection);
				BitonicSort(low + halfExLen, halfExLen, actualLength, bottomDirection);
			}//end if
			
			else{
				BitonicSort(low, halfExLen, actualLength, topDirection);
				BitonicSort(low + halfExLen, halfExLen, actualLength, bottomDirection);
			}//end else
		}//end if

		else{
			if (extendedLength == nextBiggestPowerTwo){
				BitonicSort(low, halfExLen, actualLength, bottomDirection);
				BitonicSort(low + halfExLen, actualLength - halfExLen, actualLength, topDirection);
			}//end if

			else{
				BitonicSort(low, halfExLen, actualLength, bottomDirection);
				BitonicSort(low + halfExLen, halfExLen, actualLength, topDirection);
			}//end else
		}//end else
		BitonicSortMerge(low, extendedLength, actualLength, direction);
	}//end if
}

/*Final merge step in new bitonic sort algorithm.*/
void NewBitonic::BitonicFinalMerge(int low, int extendedLength, int actualLength, bool direction, bool gap){

	int temp;
	int halfExLen = extendedLength / 2;

	//If first step, handle it special.
	if (extendedLength == nextBiggestPowerTwo){
		
		//Only move ones in special range.
		for (int i = 0; i < actualLength - halfExLen; i++)
			Compare(halfExLen-i-1, actualLength-i-1, actualLength, direction);
		
		BitonicFinalMerge(low, halfExLen, actualLength, direction, gap);
		BitonicFinalMerge(low + halfExLen, halfExLen, actualLength, direction, gap);
	}//end if

	//Second step: Do our merge to eliminate the gap if it exists.
	else if (gap && low == extendedLength / 2){
		
		if (halfExLen / 2 < nextBiggestPowerTwo - actualLength){

			//If second step, handle special
	
			//Fill gap with end elements.
			for (int i = 0; i < extendedLength*2-actualLength; i++){
				temp = numList[low+i];
				numList[low+i] = numList[low+i+extendedLength*2-actualLength];
				numList[low+i+extendedLength*2-actualLength] = temp;
			}//end for

			//Shortened comparison with middle elements.
			for (int i = 0; i < halfExLen - (extendedLength*2-actualLength); i++)
				Compare(low+i+extendedLength*2-actualLength, low+i+halfExLen, actualLength, direction);

			//Return to standard comparison. Now, no virtual gap exists.
			BitonicFinalMerge(low, halfExLen, actualLength, direction, false);
			BitonicFinalMerge(low+halfExLen, halfExLen, actualLength, direction, false);
		}//end if

		else
			BitonicFinalMerge(low, halfExLen, actualLength, direction, true);
	}//end else if

	else if (extendedLength > 1){
		
		for (int i = low; i < low+halfExLen; i++)
			Compare(i, i+halfExLen, actualLength, direction);
		BitonicFinalMerge(low, halfExLen, actualLength, direction, false);
		BitonicFinalMerge(low+halfExLen, halfExLen, actualLength, direction, false);

	}//end else if
}

/*Overridden virtual function from base Sorter class. (Sort)*/
void NewBitonic::BitonicSort(int low, int extendedLength, int actualLength, bool direction){
	
	if (extendedLength > 1){

		int halfExLen = extendedLength / 2;
		BitonicSort(low, halfExLen, actualLength, bottomDirection);
		BitonicSort(low + halfExLen, halfExLen, actualLength, topDirection);

		if (extendedLength <= actualLength)
			BitonicSortMerge(low, extendedLength, actualLength, direction);

		//If ascending:
		if (extendedLength > actualLength && bottomDirection == ascending){

			Flip(low, halfExLen);
			Flip(low + halfExLen, actualLength - halfExLen);
			BitonicFinalMerge(low, extendedLength, actualLength, descending, true);
			Flip(low, actualLength);

		}//end if

		//Else if descending:
		else if (extendedLength > actualLength)
			BitonicFinalMerge(low, extendedLength, actualLength, descending, false);

	}//end if
}

/*Overridden virtual function from base Sorter class. (Merge) */
void NewBitonic::BitonicSortMerge(int low, int extendedLength, int actualLength, bool direction){

	if (extendedLength > 1){

		int halfExLen = extendedLength / 2;

		for (int i = 0; i < actualLength-halfExLen; i++){
			
			if (extendedLength == nextBiggestPowerTwo && bottomDirection == descending)
				Compare(halfExLen-i-1, actualLength-i-1, actualLength, direction);
			
			else if (extendedLength = nextBiggestPowerTwo && bottomDirection == ascending)
				Compare(i, i+actualLength-halfExLen, actualLength, direction);
			
			else
				Compare(i, i + halfExLen, actualLength, direction);
		}//end for

		BitonicSortMerge(low, halfExLen, actualLength, direction);
		BitonicSortMerge(low+halfExLen, halfExLen, actualLength, direction);
	}//end if
}