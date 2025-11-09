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

void searchMatrix(int *arr[], int k){
	int i = 0, j=C-1;
	bool found = false;
	while(i<R && j>=0){
		if(k < arr[i][j]){
			j--;
		}
		else if(k > arr[i][j]){
			i++;
		}
		else{
			cout<<"Found at: ("<<i << ", "<<j<<") "<<endl;
			found = true;
			break;
		}
	}
	if(!found)
		cout<<"Not Found"<<endl;
}

int main(){
	int *arr[R];
	for(int i=0; i<R; i++){
		arr[i] = new int[C];
	}
	fillMatrixData(arr);
	printMatrix(arr);
	int k = 15;
	searchMatrix(arr,k);
}
