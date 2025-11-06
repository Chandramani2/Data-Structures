#include<bits/stdc++.h>
using namespace std;
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

void printsnakePattern(int *arr[]){
	for(int i=0; i<R; i++){
		if(i%2==0){
			for(int j=0; j<C; j++){
				cout<<arr[i][j]<<" ";
			}
		}
		else{
			for(int j=C-1; j>=0; j--){
				cout<<arr[i][j]<<" ";
			}
		}
		
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	int *arr[R];
	for(int i=0; i<R; i++){
		arr[i] = new int[C];
	}
	fillMatrixData(arr);
	printMatrix(arr);
	printsnakePattern(arr);
}
