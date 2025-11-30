#include "bits/stdc++.h"
using namespace std;
/* find Kth Pos after 2 sorted array is merged, 
	Note:- elements can be repeatative <- Important
*/     

/* Optimized count less than mid */
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


int countEqualTo(int arr[], int size, int K){
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

int countLessThan(int arr[], int size, int mid){
	 int low = 0;
    int high = size - 1;
    int cnt = 0;
    while (low <= high) {
        int tmpmid = (low + high) / 2;
        if (arr[tmpmid] < mid) {
            cnt = tmpmid + 1; // All elements from 0 to tmpmid are <= median
            low = tmpmid + 1;
        } else {
            high = tmpmid - 1;
        }
    }
    return cnt;
}

// can be generalizedd with number of arrays>=2 aswell
int findKthPos(int A[], int B[], int N, int M, int K){
	int medianIndex = (N+M)/2;
	int low = min(A[0], B[0]);
	int high = max(A[N-1], B[M-1]);
	int ans = A[0];
	while(low<=high){
		int mid = (low+high)/2;
		// for given mid, we'll have to find l & r, mid==l==r -> repeating elements
		int lessA = countLessThan(A, N, mid);
        int lessB = countLessThan(B, M, mid);
        int equalA = countEqualTo(A, N, mid);
        int equalB = countEqualTo(B, M, mid);

        int lessTotal = lessA + lessB;
        int equalTotal = equalA + equalB;
        // int greaterTotal = (N + M) - (lessTotal + equalTotal);

        if (lessTotal < K && lessTotal + equalTotal >= K) {
            ans = mid;
            break;
        } else if (lessTotal >= K) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
	return ans;
}

int main()
{
	int A[] = {2,4,4,6,8,8};
	int B[] = {3,4,5,5,6,7};
	int N = sizeof(A)/sizeof(A[0]);
	int M = sizeof(B)/sizeof(B[0]);
	int K =2;

	cout<<"\nKth Pos: "<<findKthPos(A,B,N,M,K);

	return 0;
}
