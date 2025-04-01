#include<bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////

void rotateArrayOnce(int arr[], int size){
    int tmp = arr[size-1];
    for(int i=size-1; i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = tmp;
}

void rotateArrayKTimesBruteForce(int arr[], int size, int k){
    for(int i=0; i<k; i++){
     rotateArrayOnce(arr,size);
    }
}

////////////////////////////////////////////////

void rotateArray(int arr[], int size, int L, int R){
    while(L<=R){
        int tmp = arr[L];
        arr[L] = arr[R];
        arr[R] = tmp;
        L++; R--;
    }
}

void rotateArrayOptimized(int arr[], int size, int k){
    rotateArray(arr,size,0,size-1);
    rotateArray(arr,size,0,k-1);
    rotateArray(arr,size,k,size-1);
}

////////////////////////////////////////////////

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {2,1,0,1,-2,3,4,-1,2,-6,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    k=k%size;
    printArray(arr,size);
    rotateArrayKTimesBruteForce(arr,size,k);
    printArray(arr,size);
    rotateArrayOptimized(arr,size,k);
    printArray(arr,size);
    return 0;
}