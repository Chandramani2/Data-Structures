#include "bits/stdc++.h"
using namespace std;

int binarySearch(int arr[], int low, int high, int X){
	int ans = INT_MIN;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]==X) return mid;
		else if(arr[mid] < X) low = mid+1;
		else high = mid-1;
	}
	return ans;
}

/*Method 1: Apply Binary Search in both part 
			of the sorted array
*/
int getElementMethod1(int arr[], int size, int K, int X){
	int part1 = binarySearch(arr,0,K-1, X);
	int part2 = binarySearch(arr,K+1,size-1, X);
	
	return (part1>part2?part1:part2);
}

/*Method 2: As K is given we can directly find in 
		which part of the sorted array X is present
*/
int getElementMethod2(int arr[], int size, int K, int X){
	int low = 0, high = size-1;
	if(X<arr[K-1] && X > arr[size-1]){
		//answer on the left sorted array
		high=K-1;
	}
	if(X<arr[K-1] && X < arr[size-1]){
		//answer on the right sorted array
		low = K+1;
	}
	
	return binarySearch(arr,low,high,X);
}

int main()
{
	int arr[] = {-15,-9,-6,0,2,5,8,10,14,18,23};
	int K=6; // Rotate Array K Times
	int rarr[] = {5,8,10,14,18,23,-15,-9,-6,0,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	int X = -6;
	cout<<"Method 1: Found at Index: "<<getElementMethod1(rarr,size,K, X);

	cout<<"\nMethod 2: Found at Index: "<<getElementMethod2(rarr,size,K, X);
	return 0;
}
