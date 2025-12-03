#include "bits/stdc++.h"
using namespace std;
/* Method 1: Apply BS every row or column*/
/* Method 2: compare last element of every row -> O(N + log(M))
if the K is smaller then we can skip Binary search on that row
*/
/* Method 3: 2 Pointer approach, take p1 & p2 at top-right position*/
/* Method 4: Apply BS on last column and take ceil of a given K
	Now along that row apply BS -> log(N) + log(M)
*/
/* Method 5: convert 2D->1D and then apply BS
	Optimize 2D->1D : without actually converting assume it as 1D and apply BS
*/
void printArray(vector<int>arr){
	for(auto x: arr){
		cout<<x<<" ";
	}
	cout<<endl;
}

int binarySearch(vector<int> arr, int K){
	int size = arr.size();
	int low = 0, high = size-1;
	int ans = -1;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]==K) return mid;
		else if(arr[mid]<K) low = mid+1;
		else high=mid-1;
	}
	return ans;
}
//Method 1 -> O(Nlog(M))
void searchMatrixBseveryRow(vector<vector<int>> mat, int K){
	for(int i=0;i<mat.size();i++){
		int ans = binarySearch(mat[i],K);
		if(ans!=-1){
			cout<<"BseveryRow: Found "+ to_string(K) + " at: "
			<<"("+ to_string(i) + ", " + to_string(ans) + ")\n";
			return;
		}
	}
	cout<<"BseveryRow: Not Found \n";
}

/* Method 5: convert 2D->1D and then apply BS */
void searchMatrix2D1D(vector<vector<int>> mat, int K){
	int N = mat.size();
	int M = mat[0].size();
	int low = 0, high = N*M-1; // 2D->1D
	while(low<=high){
		int mid = (low+high)/2;
		// index mapping 1D->2D
		int r = mid/N, c = mid%N; 
		//apply BS as 1D array
		if(mat[r][c] == K){
			cout<<"2d->1D: Found "+ to_string(K) + " at: "
			<<"("+ to_string(r) + ", " + to_string(c) + ")\n";
			return;
		}
		else if (mat[r][c] > K) high = mid-1;
		else low = mid+1;
	}
	cout<<"2d->1D: Not Found \n";
}

int main()
{	
	vector<vector<int>> mat = {
			{2, 3, 9, 10,14},
			{16,19,20,21,24},
			{27,30,33,39,40},
			{43,46,50,52,59}
	};
	int K = 30;
	searchMatrixBseveryRow(mat, K);
	searchMatrix2D1D(mat, K);
	return 0;
}
