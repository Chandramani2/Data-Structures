#include<bits/stdc++.h>
using namespace std;
/* Take Transpose of a matrix and then Reverse element column by column
Given Matrix:			1 2 3 4 
						5 6 7 8 
						9 10 11 12 
						13 14 15 16 

Transpose Matrix:		1 5 9 13 
						2 6 10 14 
						3 7 11 15 
						4 8 12 16 

Rotated Matrix:			4 8 12 16 
						3 7 11 15 
						2 6 10 14 
						1 5 9 13 
*/
const int R = 4;
const int C = 4;

void printMatrix(int *arr[]){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void fillMatrixData(int *arr[]){
	int cnt=1;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			arr[i][j] = cnt;
			cnt++;
		}
	}
}

void TransposeMatrix(int *arr[]){
	for(int i=0; i<R; i++){
		for(int j=i+1; j<C; j++){
			swap(arr[i][j], arr[j][i]);
		}
	}
}

void rotateMatrixBy90(int *arr[]){
	TransposeMatrix(arr);
	printMatrix(arr);
	for(int col=0; col<C; col++){
		int i=0, j=R-1;
		while(i<=j){
			swap(arr[i][col], arr[j][col]);
			i++;
			j--;
		}
	}
}

int main(){
	int *arr[R];
	for(int i=0; i<R; i++){
		arr[i] = new int[C];
	}
	fillMatrixData(arr);
	printMatrix(arr);
	rotateMatrixBy90(arr);
	printMatrix(arr);
}
