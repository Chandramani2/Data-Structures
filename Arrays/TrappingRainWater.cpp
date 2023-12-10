#include<bits/stdc++.h>
using namespace std;

void leftMax(vector<int> &arr, vector<int> &lMax, int n){
	lMax[0] = arr[0];
	int maxTillNow = arr[0];
	for(int i= 1;i<n ;i++){
		if(arr[i]>maxTillNow){
			maxTillNow = arr[i];
		}
			lMax[i] = maxTillNow;
		
	}
}
void rightMax(vector<int> &arr, vector<int> &rMax, int n){
	rMax[n-1] = arr[n-1];
	int maxTillNow = arr[n-1];
	for(int i= n-2;i>=0;i--){
		if(arr[i]>maxTillNow){
			maxTillNow = arr[i];
		}
			rMax[i] = maxTillNow;
		
	}
}
int maxTrappedWater(vector<int> &arr){
	int n = arr.size();
	vector<int> lMax(n,INT_MIN);
	vector<int> rMax(n,INT_MIN);
	leftMax(arr,lMax,n);
	rightMax(arr,rMax,n);
	cout<<"Left Max Array: ";
	for(int a: lMax){
		cout<<a<<" ";
	}
	cout<<endl;
	cout<<"Right Max Array: ";
	for(int a: rMax){
		cout<<a<<" ";
	}
	cout<<endl;
	int ans = 0;
	for(int i=1;i<n-1;i++){
		int currentBar = min(lMax[i-1], rMax[i+1]);
		if(currentBar > arr[i]){
			ans += currentBar - arr[i];
		}
	}
	return ans;
}
int main(){
	 vector<int> arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }; 
	 int ans = maxTrappedWater(arr);
	 cout<<"Total Trapped Rain Water: "<<ans;
	return 0;
}