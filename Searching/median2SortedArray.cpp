#include "bits/stdc++.h"
using namespace std;
/* find median after 2 sorted array is merged, 
	Note:- all elements are distinct
*/

/* Method 1: Take 2 pointers P1 & P2 and move in sorting manner
	until the count becomes medianIndex
	median at - no. of elements less than medianIndex
*/
int getMedian(int A[], int B[], int N, int M){
	int medianIndex = (N+M)/2;
	int p1=0,p2=0;
	int cnt=0;
	while(p1<N && p2<M && cnt<medianIndex){
		if(A[p1]<B[p2]) p1++;
		else p2++;
		cnt++;
	}
	return min(A[p1], B[p2]);
}

/* Method 2: Binary Search */
int countLessThanMid(int arr[], int size, int mid){
	int cnt = 0;
	for(int i=0;i<size;i++){
		if(arr[i] < mid) cnt++;
		else break;
	}
	return cnt;
}

/* Optimized count less than mid */
int countLessThanMidOptimized(int arr[], int size, int median){
	 int low = 0;
    int high = size - 1;
    int cnt = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < median) {
            cnt = mid + 1; // All elements from 0 to mid are <= median
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return cnt;
}

int getMedianBS(int A[], int B[], int N, int M){
	int medianIndex = (N+M)/2;
	int ans = -1;
	int low = min(A[0], B[0]);
	int high = max(A[N-1], B[M-1]);
	while(low<=high){
		int mid = (low+high)/2;
		int cntEleLessThanMid = countLessThanMidOptimized(A,N,mid)
							  + countLessThanMidOptimized(B,M,mid);
		cout<<"No. of element Less than "+ to_string(mid) +
		": "<<cntEleLessThanMid<<endl;
		/* There might be number not present in the Array
		In this case 12,13,14,15 all will give 5(medianIndex) as o/p
		we have to look for better answer on the right side 
		*/
		if(cntEleLessThanMid == medianIndex) {
			ans = mid;
			low = mid+1;
		}
		if(cntEleLessThanMid > medianIndex) high = mid-1;
		else low = mid+1;
	}
	return ans;
}

int main()
{
	int A[] = {2,6,11,19,25, 30};
	int B[] = {8,9,15,29,40};
	int N = sizeof(A)/sizeof(A[0]);
	int M = sizeof(B)/sizeof(B[0]);

	cout<<"Median: "<<getMedian(A,B,N,M)<<endl;
	cout<<"Median: "<<getMedianBS(A,B,N,M);

	return 0;
}
