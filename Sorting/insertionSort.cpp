#include<bits/stdc++.h>
using namespace std;

void insertionSOrt(vector<int> &arr, int n){
	// assume 0-i is already sorted
	for(int i = 0; i<n-1; i++){
		for(int j = i; j>=0; j--){
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void printArray(vector<int> &arr){
	for(auto x: arr){
		cout<<x<< " ";
	}
}
int main(){
	vector<int> arr = {15,4,10,6,1,8,13,14,17,3,12,10,11,6,5,1};
	int n = arr.size();
	insertionSOrt(arr, n);
	printArray(arr);
	return 0;

}


