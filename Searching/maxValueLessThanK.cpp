#include "bits/stdc++.h"
using namespace std;

int maxValueLessThanK(int arr[], int size, int K){
	int low = 0, high = size-1;
	int ans = INT_MIN;
	while(low<=high){
		int mid = (low+high)/2;

		if(arr[mid] <= K){
			ans = max(ans, arr[mid]);
			low = mid+1;
		}
		else high = mid-1;
	}	
	return ans;				
}

int main()
{
	int arr[] = {6,2,3,-5,10,18,9,11,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	sort(arr, arr+size); // Binary search requires sorted array
	int K=20;
	cout<<"Max Value Less than "+ to_string(K)+": "
	<<maxValueLessThanK(arr,size,K);
	
	return 0;
}
