#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr, int n, int ind, int prevIndex){
	if( ind==n ) return 0;

	int notTake = 0 + LIS(arr,n,ind+1,prevIndex);
	int take = INT_MIN;
	if(prevIndex==-1 || arr[ind] > arr[prevIndex]){
		take = 1 + LIS(arr,n,ind+1,ind);
	}
	return max(take,notTake);
}

int LISMemo(vector<int> &arr, int n, int ind, int prevIndex, vector<vector<int>> &dp){
	if( ind==n ) return 0;
  	if(dp[ind][prevIndex+1]!=-1) return dp[ind][prevIndex+1];
	int notTake = 0 + LISMemo(arr,n,ind+1,prevIndex,dp);
	int take = INT_MIN;
	if(prevIndex==-1 || arr[ind] > arr[prevIndex]){
		take = 1 + LISMemo(arr,n,ind+1,ind,dp);
	}
	return dp[ind][prevIndex+1] = max(take,notTake);
}

int LISDp(vector<int> &arr, int n,  vector<int> &lis){
	lis[0] = 1;

	for(int i=1;i<n;i++){
		lis[i] = 1;
		for(int j=i;j>=0;j--){
			if(arr[j]<arr[i] && lis[i]<lis[j]+1){
				lis[i] = lis[j]+1;
			}
		}
	}
	return *max_element(lis.begin(),lis.end());
}

void print2DArray(vector<vector<int>> &arr){
	int n = arr.size();
	int m = arr[0].size();

	for(int i=0;i<n;i++){
		for(auto x: arr[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

void printArray(vector<int> &arr){
	int n = arr.size();
	
	for(auto x: arr){
		cout<< x <<" ";
	}
	cout<<endl;
	
}
int main(){
	vector<int> arr = {10,3,12,7,2,9,8,20,11,13,6,8};
	int n = arr.size();
	cout<<"LIS : "<<LIS(arr,n, 0, -1)<<endl;

	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	cout<<"LIS Memoization : "<<LISMemo(arr,n, 0, -1, dp)<<endl;
	print2DArray(dp);

	vector<int> lis(n,-1);
	cout<<"LIS Dp : "<<LISDp(arr,n, lis)<<endl;
	printArray(lis);
	return 0;
}