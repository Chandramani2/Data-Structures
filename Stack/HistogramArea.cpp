#include<bits/stdc++.h>
using namespace std;

int maxHistogramArea(vector<int> &arr){
	int n = arr.size();
	vector<int> p1(n,-1); // previous smaller
	vector<int> p2(n,n);  // next smaller
	int ans = -1;
	for(int i=0;i<n;i++){
		int nextSmaller = n;
		int prevSmaller = -1;
		for(int j=i;j<n;j++){
			if(arr[j]<arr[i]) {
				nextSmaller = j; break;
			}
		}
		for(int j=i;j>=0;j--){
			if(arr[j]<arr[i]) {
				prevSmaller = j; break;
			}
		}
		int area = (nextSmaller - prevSmaller - 1) * arr[i];
		ans = max(ans, area);
	}
	return ans;
}

void fillNextSmaller(vector<int> &p2, vector<int> &arr, int n){
	stack<pair<int,int>> st;
	st.push({arr[0],0});
	for(int i=1;i<n;i++){
		pair<int,int> tmp = st.top();
		int data = tmp.first;
		int ind = tmp.second;
		
		if(arr[i] > data){
			st.push({arr[i],i});
		}
		else{

			while(!st.empty() && st.top().first > arr[i]){

				p2[st.top().second] = i;
				st.pop();
			}
		}
		st.push({arr[i],i});
	}

}
void fillPreviousSmaller(vector<int> &p2, vector<int> &arr, int n){
	stack<pair<int,int>> st;
	st.push({arr[n-1],n-1});
	for(int i=n-2;i>=0;i--){
		pair<int,int> tmp = st.top();
		int data = tmp.first;
		int ind = tmp.second;
		
		if(arr[i] > data){
			st.push({arr[i],i});
		}
		else{

			while(!st.empty() && st.top().first > arr[i]){

				p2[st.top().second] = i;
				st.pop();
			}
		}
		st.push({arr[i],i});
	}
}
void printArray(vector<int> &arr){
	cout<<endl;
	for(auto x: arr){
		cout<<x<<" ";
	}
	cout<<endl;
}
int maxHistogramAreaStack(vector<int> &arr){
	int n = arr.size();
	vector<int> p1(n,-1); // previous smaller
	vector<int> p2(n,n);  // next smaller
	int ans = -1;
	fillNextSmaller(p2,arr,n);
	fillPreviousSmaller(p1, arr,n);
	printArray(p2);
	printArray(p1);

	for(int i=0;i<n;i++){
		int area = (p2[i] - p1[i] - 1) * arr[i];
		ans = max(ans,area);
	}
	return ans;
}

int main(){
	vector<int> arr = { 6, 2, 5, 4, 5, 1, 6 };
	cout<<"Max Histogram Area: "<<maxHistogramArea(arr)<<endl;
	cout<<"Max Histogram Area: "<<maxHistogramAreaStack(arr);
	return 0;
}