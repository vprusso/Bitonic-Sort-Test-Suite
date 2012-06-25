/*
Main.cpp: 
Driver file for bitonic sort test suites.
*/

//Primary sorter class
#include "Sorter.h"

//Bitonic methods
#include "Padding.h"
#include "VirtualPadding.h"
#include "NewBitonic.h"

//Misc parallel sort methods.
#include "RadixSort.h"
#include "BucketSort.h"

//Select which algorithm to run (uncomment which you wish to run, others will not run).
//#define paddingTest
//#define virtualPaddingTest
//#define newBitonicTest
//#define radixTest
//#define bucketTest

int main(){

	/*Class variables*/

	//Primary sorter
	Sorter sorter;

	//Bitonic methods
	Padding padding;
	VirtualPadding virtualPadding;
	NewBitonic newBitonic;

	//Misc. Parallel sorts
	RadixSort radixSort;
	BucketSort bucketSort;

	/*Element and timing variables.*/
	vector<int> nums;					//Numbers to sort.
	unsigned numElements = 1000;		//Amount of numbers to sort.
	int trials = 5;						//Number of trials to run.
	clock_t start;						//Timing variable.
	ofstream resultsFile;				//Text file for results to be written.

	//Fill vector with random numbers
	for (unsigned i = 0; i < numElements; i++)
		nums.push_back(rand());

	/*---------------------------------------------------------------------------------*/
	/*                              BITONOIC SORT METHODS                              */
	/*---------------------------------------------------------------------------------*/

	/***********************************************************************************/
	/*									PADDING TESTS								   */
	/***********************************************************************************/
#ifdef paddingTest

	resultsFile.open("PaddingResults.txt");

	for (int i = 0; i < trials; i++){

		//If the size is not a power of two.
		if (!sorter.isPowerTwo(nums.size()))
			nums.resize(sorter.GetNextBiggestPowerTwo(nums.size()));

		/*Time Trials*/
		start = clock();
		vector<int> padVec = padding.BitonicSort(nums,true);	
		cout << "***Trial " << i+1 << "***" <<endl;
		cout << "Padding Method with " << numElements << " elements" << endl;
		printf("Time elapsed: %f\n\n", ( (double)clock() - start) / CLOCKS_PER_SEC);

		/*Write to text file*/
		resultsFile << ( (double)clock() - start) / CLOCKS_PER_SEC << endl;

	}//end for

	resultsFile.close();
#endif
	/***********************************************************************************/


	/***********************************************************************************/
	/*							      VIRTUAL PADDING TESTS							   */
	/***********************************************************************************/
#ifdef virtualPaddingTest
	for (int i = 0; i < trials; i++){

		/*Time Trials*/
		start = clock();

		cout << "***Trial " << i+1 << "***" <<endl;
		cout << "Virtual Padding Method with " << numElements << " elements" << endl;
		printf("Time elapsed: %f\n\n", ( (double)clock() - start) / CLOCKS_PER_SEC);

	}//end for
#endif virtualPaddingTest

	/***********************************************************************************/

	/***********************************************************************************/
	/*									NEW BITONIC TESTS							   */
	/***********************************************************************************/
#ifdef newBitonicTest
	for (int i = 0; i < trials; i++){
		/*Time Trials*/
		start = clock();
		newBitonic.SortAscending(nums,true);	
		cout << "New Bitonic Method with " << numElements << " elements" << endl;
		printf("Time elapsed: %f\n\n", ( (double)clock() - start) / CLOCKS_PER_SEC);
	}//end for
#endif
	/***********************************************************************************/


	/*---------------------------------------------------------------------------------*/
	/*                            MISC PARALLEL SORT METHODS                           */
	/*---------------------------------------------------------------------------------*/

	/***********************************************************************************/
	/*									  RADIX SORT		     					   */
	/***********************************************************************************/

#ifdef radixTest
	for (int i = 0; i < trials; i++){
		/*Time Trials*/
		start = clock();
		radixSort.RadixSortAlg(nums);	
		cout << "Radix sort with " << numElements << " elements" << endl;
		printf("Time elapsed: %f\n\n", ( (double)clock() - start) / CLOCKS_PER_SEC);
	}//end for
#endif 
	/***********************************************************************************/

	/***********************************************************************************/
	/*									  BUCKET SORT		     					   */
	/***********************************************************************************/

#ifdef bucketTest
	for (int i = 0; i < trials; i++){
		/*Time Trials*/
		start = clock();
		//vector<int> bucketVec = radixSort.BitonicSort(nums,true);	
		cout << "Bucket Sort with " << numElements << " elements" << endl;
		printf("Time elapsed: %f\n\n", ( (double)clock() - start) / CLOCKS_PER_SEC);
	}//end for
#endif 
	/***********************************************************************************/

	return 0;
}