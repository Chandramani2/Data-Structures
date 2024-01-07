#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
	vector<int> tmp(high - low +1, -1);
	int p1 = low, p2 = mid+1, p3 = 0;
	while(p1<=mid && p2<=high){
		if(arr[p1] > arr[p2])tmp[p3++] = arr[p2++];
		else tmp[p3++] = arr[p1++];
	}
	while(p1<=mid) {tmp[p3++] = arr[p1++];}
	while(p2<=high){tmp[p3++] = arr[p2++];}

	for(int i = low; i<=high; i++){
		arr[i] = tmp[i-low];
	}
}
void MS(vector<int> &arr, int low, int high){
	if(low == high) return;
	int mid  = (low + high) /2;
	MS(arr, low, mid);
	MS(arr, mid+1, high);
	merge(arr, low, mid, high);

}
void mergeSort(vector<int> &arr, int n){
	int low = 0;
	int high = n-1;	
	MS(arr, low, high);
}

void printArray(vector<int> &arr){
	for(auto x: arr){
		cout<<x<< " ";
	}
}
int main(){
	vector<int> arr = {15,4,10,6,1,8,13,14,17,3,12,10,11,6,5,1};
	int n = arr.size();
	mergeSort(arr,n);
	printArray(arr);
	return 0;

}
