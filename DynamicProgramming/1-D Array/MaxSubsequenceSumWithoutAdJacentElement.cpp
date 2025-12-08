#include<bits/stdc++.h>
using namespace std;

int subsequenceSum(vector<int> &arr,int n, int ind){

	if(ind>=n) return 0;
	return max(
		arr[ind]+
		subsequenceSum(arr,n,ind+2), 
		subsequenceSum(arr,n,ind+1));
}

int subsequenceSumDp(vector<int> &arr,int n, int ind, 
					vector<int> &dp){

	if(ind>=n) return 0;
	if(dp[ind]!=INT_MIN) return dp[ind];
	return dp[ind] = max(
		arr[ind]+
		subsequenceSumDp(arr,n,ind+2,dp), 
		subsequenceSumDp(arr,n,ind+1,dp));
}

//IterativeApproach
int iterativeSolution(vector<int> &arr, int n, vector<int> &dp){
	dp[0] = arr[0];
	dp[1] = arr[1];

	int ans = dp[0];
	for(int i=2;i<n;i++){
		dp[i] = arr[i] + max(0,ans);
		ans = max(ans,dp[i-1]);
	}
	return *max_element(dp.begin(),dp.end());
}

void printArray(vector<int> &arr){
	cout<<endl;
	for(auto x: arr){
		cout<<x<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> arr = {3,5,2,8,-3,18,4,10,6,12,-5,-2,-4}; //ans = 57
	int n = arr.size();
	int ans = subsequenceSum(arr,n,0);
	cout<<" Max Subsequence SUM Without Adjacent Element is : "
	<<ans<<endl;

	vector<int>dp(n,INT_MIN);
	ans = subsequenceSumDp(arr,n,0,dp);
	cout<<" Max Subsequence SUM Without Adjacent Element is [DP]: "
	<<ans<<endl;
	
	fill(dp.begin(),dp.end(),INT_MIN);
	ans = iterativeSolution(arr,n,dp);
	cout<<" Max Subsequence SUM Without Adjacent Element is (Space Optimized) : "
	<<ans<<endl;
	printArray(dp);
	return 0;
}