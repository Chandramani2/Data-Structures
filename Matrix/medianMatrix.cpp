#include<bits/stdc++.h>
using namespace std;
/* Naive Solution:
	1. Take all the elements into an array
	2. Sort the Array
	3. Return the Middle element of the Array
	
	Efficient Solution:
*/
const int R = 3;
const int C = 3;

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void printMatrix(int *mat[]){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void fillMatrixData(int *mat[]){
	// Seed the random number generator
    srand(time(0));

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			mat[i][j] = rand() % 100;
		}
		sort(mat[i], mat[i]+C); // Creating a Row-wise sorted Matrix
	}
}

void medianMatrixNaive(int *mat[]){
	int size = R*C;
	int arr[size];
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			arr[i*C+j] = mat[i][j];
		}
	}
	printArray(arr, size);
	sort(arr, arr+size);
	cout<<"After Sorting: "<<endl;
	printArray(arr,size);
	cout<<"Median of the Matrix is: ";
	int median;
	if(size%2!=0){
		median= arr[size/2];
	}
	else{
		median = (arr[(size-1)/2] + arr[size/2])/2;
	}
	cout<<median<<endl;
}

void medianMatrixOptimized(int *mat[]){
	// it's Row-wise sorted so find min element in 1st column and max element in last column
	int minEle=mat[0][0], maxEle=mat[0][C-1];
	for(int i=1; i<R; i++){
		if(mat[i][0]<minEle)
			minEle = mat[i][0];
		if(mat[i][C-1]>maxEle)
			maxEle = mat[i][C-1];
	}
	int totalEle = R*C;
	int medPos = (totalEle+1)/2;
	
	//Now we have to find how many elements are less than mid to get the median and it should be exacly as 'median' totalEle/2
	
	while(minEle<maxEle){
		int mid = (minEle+maxEle)/2;
		int midPos = 0; 
		// Traverse every row and find how many elements are less than mid
		for (int i = 0; i < R; i++)
			midPos += upper_bound(mat[i], mat[i]+C, mid) - mat[i];

		if(midPos<medPos) minEle = mid+1;
		else maxEle = mid;
	}
	cout<<"Optimized: "<<minEle;
}

int main(){
	int *mat[R];
	for(int i=0; i<R; i++){
		mat[i] = new int[C];
	}
	fillMatrixData(mat);
	printMatrix(mat);
	medianMatrixNaive(mat);
	medianMatrixOptimized(mat);
}
