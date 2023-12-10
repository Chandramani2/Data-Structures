#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr){
	for(int a: arr){
		cout<<a<< " ";
	}
}
void sort0To2(vector<int> &arr, int n){
	int low = 0;
	int mid = 0; // used to identify 0 or 2..... (if 0 swap with low) and (if 2 swap with high) .... sort extremes then mid already sorted
	int high = n-1;

	while(mid<=high){
		if(arr[mid]==0){
			swap(arr[low],arr[mid]);
			low++;mid++;
		}
		else if(arr[mid]==2){
			swap(arr[high], arr[mid]);
			high--;
		}
		else{
			mid++;
		}
	}
	printArray(arr);

}

int main(){
	 vector<int> arr = {0,0,1,2,0,0,2,1,0,2,1,0,1,2,1,2,0,1,0,2,1,2};
	int n = arr.size();
	sort0To2(arr, n);
	return 0;
}