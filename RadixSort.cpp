/*
RadixSort.cpp:
	Class implementation for radix sort algorithm
*/

#include "RadixSort.h"

void RadixSort::PutInQueues(queue<int> q[],  int qcount, vector<int> &data, int digit){
	
	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter){
		int qpos = GetDigitAt(*iter, digit);
		q[qpos].push(*iter);
	}
}

void RadixSort::GetPartialSorted(queue<int> q[], int qcount, vector<int> &data){
	
	for (int i = 0; i < qcount; ++i){
		if (q[i].size() > 0){
			int length = q[i].size();
			while(length--){
				data.push_back(q[i].front());
				q[i].pop();
			}
		}
	}
}

int RadixSort::FindMaxDigits(vector<int> &data){
	vector<int>::const_iterator iter = data.begin();
	int max = 0;
	for (; iter!= data.end(); ++iter){
		int numd = NumDigits(*iter);
		if(max < numd){
			max = numd;
		}
	}
	return max;
}

int RadixSort::NumDigits(int n){
	int count = 0;
	while(n != 0){
		n = n / 10;
		++count;
	}
	return count;
}

void RadixSort::RadixSortAlg(vector<int> &data){
	
	queue<int> q[10];
	int maxDigits = FindMaxDigits(data);

	for (int i = 0; i < maxDigits; ++i){
		PutInQueues(q, 10, data, i+1);
		data.clear();
		GetPartialSorted(q,10,data);
	}

}

int	RadixSort::GetDigitAt(int n, int digit){

	int dig = 0;
	while(digit--){
		dig = n % 10;
		n = n / 10;
	}
	return dig;

}