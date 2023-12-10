#include<bits/stdc++.h>
using namespace std;

int maxAdjacentSumHelper(int i, vector<int> &arr){
	if(i==0) return arr[i];
	if(i<0) return 0;
	int pick =  arr[i] + maxAdjacentSumHelper(i-2,arr);
	int nopick = maxAdjacentSumHelper(i-1,arr);
	
	return max(pick,nopick);
}

int maxAdjacentSumHelperDP(int i, vector<int> &arr, vector<int> &dp){
	if(i==0) return arr[i];
	if(i<0) return 0;
	if(dp[i]!=-1) return dp[i];
	int pick =  arr[i] + maxAdjacentSumHelperDP(i-2,arr,dp);
	int nopick = maxAdjacentSumHelperDP(i-1,arr,dp);
	
	return dp[i] =  max(pick,nopick);
}


int maxAdjacentSum(vector<int> &arr, int n){
	// return maxAdjacentSumHelper(n-1, arr);
	vector<int> dp(n,-1);
	return maxAdjacentSumHelperDP(n-1,arr,dp);
}

int main(){
	 vector<int> arr = { 5, 5, 10, 100, 10, 5 }; 
	 int n = arr.size();
	 cout<<"Max Sum With No Adjacent Element: "<<maxAdjacentSum(arr, n);;
	
	return 0;
}