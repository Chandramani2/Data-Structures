#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    
    // Outer loop for passes
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Use boolean flag
        
        // Inner loop for comparison
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // Optimization: If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}

void printArray(vector<int> &arr){
	for(auto x: arr){
		cout<<x<< " ";
	}
}
int main(){
	vector<int> arr = {15,4,10,6,1,8,13,14,17,3,12,10,11,6,5,1};
	bubbleSort(arr);
	printArray(arr);
	return 0;

}


