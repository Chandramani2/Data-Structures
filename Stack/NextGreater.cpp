#include<bits/stdc++.h>
using namespace std;

void nextGreater(vector<int> &arr, int n , vector<int> &ans){
	stack<int>st;
	st.push(0);
	for(int i=1;i<n;i++){
		int topEle = arr[st.top()];
		
		if(arr[i] < topEle){
			st.push(i);
		}
		else{	
				while(!st.empty() && arr[st.top()] < arr[i]){
					int ind = st.top();
					ans[ind] = arr[i];
					st.pop();
					
				}
			
		}
		st.push(i);
	}
}

int main(){
	vector<int> arr = {3,5,2,10,30,2,4,8,1,25,4,3,10,15,8,5,14};
	int n = arr.size();
	vector<int>ans(n,-1);
	nextGreater(arr,n,ans);
	cout<<endl;
	for(auto x:ans){
		cout<<x<<" ";
	}
	return 0;
}