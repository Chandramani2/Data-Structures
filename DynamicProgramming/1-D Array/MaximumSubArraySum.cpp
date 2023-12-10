#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &arr, int n){
	// Let's suppose max Subarray Sum ending at ith index
	vector<int>dp(n,-1);
	dp[0] = arr[0];
	for(int i=1;i<n;i++){
		dp[i] = max(arr[i], dp[i-1] + arr[i]);
	}
	return *max_element(dp.begin(), dp.end());
}

int maxSubArraySumSpaceOptimized(vector<int> &arr, int n){
	int curr = arr[0];
	int prev = arr[0];
	int ans = INT_MIN;
	for(int i=1;i<n;i++){
		curr = max(arr[i], prev + arr[i]);
		ans = max(ans, curr);
		prev = curr;
	}
	return ans;
}

int main(){
	 vector<int> arr = { -2, -3, 4, -1, -2, 1, 5, -3 }; 
	 int n = arr.size();
	 int ans = maxSubArraySum(arr, n);
	 cout<<"Max Subarray Sum: "<<ans<<endl;
	 ans = maxSubArraySumSpaceOptimized(arr, n);
	 cout<<"Max Subarray Sum: "<<ans;
	return 0;
}