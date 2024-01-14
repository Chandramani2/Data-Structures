#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n){
	
	for(int i = 0;i<n; i++){
		int minSofar=arr[i], ind = i;
		for(int j = i; j<n;j++){
			if(arr[j] < minSofar){
				minSofar = arr[j];
				ind = j;
			}
		}
		swap(arr[ind], arr[i]);
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
	selectionSort(arr, n);
	printArray(arr);
	return 0;

}


