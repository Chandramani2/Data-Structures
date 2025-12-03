#include "bits/stdc++.h"
using namespace std;

// Naive approach
int findFrequencyNaive(int arr[], int size, int K){
	int low = 0, high = size-1;
	int ans = INT_MIN;
	int cntLeft=0,cntRight=0;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]==K){
			//count Left
			for(int i=mid;i>=0;i--){
				if(arr[i]==K) cntLeft++;
				else break;
			}
			// count right
			for(int i=mid+1;i<size; i++){
				if(arr[i]==K) cntRight++;
				else break;
			}
			return cntLeft+cntRight;
		}
		if(arr[mid] < K){
			low = mid+1;
		}
		else high = mid-1;
	}	
	if(cntLeft==0 && cntRight==0) return 0;
	return ans;				
}

/* ************************************************ */

// Optimized Approach
// Find first occurrence of K using binary search
int firstOccurrence(int arr[], int size, int mid, int K) {
    int low = 0, high = mid;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == K) {
            result = mid;
            high = mid - 1; // search left for first occurrence
        } else if (arr[mid] < K) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Find last occurrence of K using binary search
int lastOccurrence(int arr[], int size, int mid, int K) {
    int low = mid, high = size - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == K) {
            result = mid;
            low = mid + 1; // search right for last occurrence
        } else if (arr[mid] < K) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}


int findFrequency(int arr[], int size, int K){
	int low = 0, high = size-1;
	int ans = INT_MIN;
	int leftIndex=-1,rightIndex=-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]==K){
			//count Left
			leftIndex = firstOccurrence(arr, size, mid, K);
			// count right
			rightIndex = lastOccurrence(arr, size, mid, K);

			return (rightIndex-leftIndex+1);
		}
		if(arr[mid] < K){
			low = mid+1;
		}
		else high = mid-1;
	}	
	if(leftIndex == -1) return	0;
	return ans;				
}

int main()
{
	int arr[] = {-5,-5,-3,0,0,1,1,5,5,5,5,5,5,5,8,10,10,15,15};
	int size = sizeof(arr)/sizeof(arr[0]);
	int K=7;
	cout<<"BF: Frequency of "+ to_string(K)+": "
	<<findFrequencyNaive(arr,size,K);
	cout<<"\nOptimized: Frequency of "+ to_string(K)+": "
	<<findFrequency(arr,size,K);
	return 0;
}
