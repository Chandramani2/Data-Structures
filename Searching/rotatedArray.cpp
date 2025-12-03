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

/* Find K first for the rotated sorted array
*/
int findK(int arr[], int size){
	int low = 0, high=size-1;
	int K;
	while(low<=high){
		int mid = (high+low)/2;
		if(arr[mid] >= arr[0]){
			low = mid+1;
		}
		if(arr[mid] < arr[0]){
			K = mid;
			high = mid-1;
		}
	}
	return K;
}

/* As we got K we can directly find in 
		which part of the sorted array X is present
*/
int getElement(int arr[], int size, int X){
	int low = 0, high = size-1;
	int K = findK(arr,size);
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
	int rarr[] = {5,8,10,14,18,23,-15,-9,-6,0,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	int X = -6;
	cout<<"Found at Index: "<<getElement(rarr,size,X);
	return 0;
}
