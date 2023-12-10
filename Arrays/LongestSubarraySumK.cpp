#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, int k, int n){

	vector<int> pfSum(n,0);
	pfSum[0] = arr[0];
	for(int i=1;i<n;i++){
		pfSum[i] = pfSum[i-1] + arr[i];
	}
	cout<<"Prefix Sum: ";
	for(int a: pfSum){
		cout<< a<< " ";
	}
	cout<<endl;

	unordered_map<int,int> mp;
	mp.insert({0,-1});
	int ans = 0;
	for(int i=0;i<n;i++){
		int ele = pfSum[i] - k;
		if(mp.find(ele)!=mp.end()){	
			ans = max(ans, i-mp[ele]);
			cout<<ans<<": "<<i<<" "<< mp[ele]<<endl;	
		}
		else{
			mp[pfSum[i]]=i;
		}
		

	}
	return ans;
}

int main(){
	 vector<int> arr = {-5, 8, -14, 2, 4, 12};
	 int k = -5; //Here ans = 5 ---> from -5 to 4 = sum is -5
	 int n = arr.size();
	 int ans = longestSubarrayWithSumK(arr, k, n);
	 cout<<"Largest Subarray With Sum K: "<<ans;
	return 0;
}