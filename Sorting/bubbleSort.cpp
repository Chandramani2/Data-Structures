#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n){
	for(int i = 0 ; i < n-1 ; i++){
		int cnt = 0;
		for(int j=0; j < n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				cnt++;
			}
		}
		if(cnt==0) break;
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
	bubbleSort(arr, n);
	printArray(arr);
	return 0;

}


