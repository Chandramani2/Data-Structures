#include<bits/stdc++.h>
using namespace std;

void prefixSum(vector<int> &arr, vector<int> &pf, int n){
	pf[0] = arr[0];
	for(int i=1;i<n;i++){
		pf[i] = arr[i] + pf[i-1];
	}
}
void printPFArray( vector<int> &pf){
	cout<<"Prefix Sum: ";
	for(auto x: pf){
		cout<<x<<" ";
	}
	cout<<endl;
}
//pre-computation , Replace 0 with -1 and take PrefixSum
void preComputation(vector<int>&arr){
	for(auto it = arr.begin(); it!=arr.end(); it++){
		if(!*it) *it=-1;
	}
	//This will not work
	// for(auto x:arr){
	// 	if(!x) x=-1;
	// }
}
int equalZeroAndOnes(vector<int> &arr, int n, int &p1, int &p2, int &ans){
	preComputation(arr);
	unordered_map<int,int>hm;
	vector<int> pf(n,0);
	prefixSum(arr,pf,n);
	printPFArray(pf);
	//Edge Case when complete array sum is 0. e.g; 1,2,-3
	hm.insert({0,-1}); 
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
	return ans;
}

int main(){
	vector<int> arr = {0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,0,1,1,0};
	int p1=-1,p2=-1, ans= -1;
	int n = arr.size();
	equalZeroAndOnes(arr,n,p1,p2,ans);
	cout<<"Longest Subarray With Sum Zero: "<<ans<<" Range From :"<<p1+1<<" to "<<p2;
	return 0;
}