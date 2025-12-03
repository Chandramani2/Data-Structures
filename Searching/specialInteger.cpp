#include "bits/stdc++.h"
using namespace std;
/* given array with all +ve integers, find max K such that,
	there is no subarray sum of size K > B
	e.g:{3,2,6,9,4,7,8} and B=20
	K=3 is answer because:
	3+2+6, 2+6+9, 6+9+4, 9+4+7 and 4+7+8 <= 20
*/
void printArray(vector<int>arr){
	for(auto x: arr){
		cout<<x<<" ";
	}
	cout<<endl;
}

// K acting as mid in BS TTTTTFFFFFF pattern
bool check(vector<int> arr, int K, int B){
	int N = arr.size();
	int sum = 0, maxSum = 0;
	// 1st subarray [0,K-1]
	for(int i=0; i<K; i++){
		sum+=arr[i];
	}
	maxSum = max(maxSum, sum);

	for(int i=K; i<N; i++){
		sum = sum + arr[i] - arr[i-K]; //sliding window
		maxSum = max(maxSum, sum);
	}
	// maxSum contains max subarray sum of subArrays of size K
	if(maxSum<=B) return true;
	return false;
}

int maxKsubarraySum(vector<int> arr, int B){
	int N = arr.size();
	int ans = -1;
	int low = 0, high=N-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(check(arr,mid,B)){
			ans = mid;
			low=mid+1;
		}
		else high = mid-1;
	}
	return ans;
}

int main()
{	
	vector<int> arr = {3,2,6,9,4,7,8};
	int B = 20;
	cout<<maxKsubarraySum(arr, B);
	return 0;
}
