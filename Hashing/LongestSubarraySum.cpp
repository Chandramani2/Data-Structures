#include<bits/stdc++.h>
using namespace std;

void prefixSum(vector<int> &arr, vector<int> &pf, int n){
	pf[0] = arr[0];
	for(int i=1;i<n;i++){
		pf[i] = arr[i] + pf[i-1];
	}
}
void printPFArray( vector<int> &pf, int n){
	cout<<"Prefix Sum: ";
	for(auto x: pf){
		cout<<x<<" ";
	}
	cout<<endl;
}
void longestSubarraySum0(vector<int> &arr, int n, int &p1, int &p2, int &ans){
	unordered_map<int,int>hm;
	vector<int> pf(n,0);
	prefixSum(arr,pf,n);
	printPFArray(pf,n);
	
	for(int i=0;i<n;i++){ // start inserting element on the fly and calculate the length when it's a match again
		if(hm.find(pf[i])==hm.end()){
			hm.insert({pf[i], i});
		}
		else{
			int x = hm[pf[i]];
			if((i-x) > ans){ // we got answer of greater length
				p1 = x;
				p2 = i;
				ans = i-x;
			}
		}
	}
	// return ans;
}

int main(){
	vector<int> arr = {3,3,4,-5,-2,2,1,-3,3,-1,5,-4,-1};
	int p1=-1,p2=-1, ans= -1;
	int n = arr.size();
	longestSubarraySum0(arr,n,p1,p2,ans);
	cout<<"Longest Subarray With Sum 0: "<<ans<<" Range From :"<<p1<<" to "<<p2;
	return 0;
}