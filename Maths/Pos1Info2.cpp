#include<bits/stdc++.h>
using namespace std;
/*
    Given an array of size N, re-arrange array value
    such that arr[i] = arr[arr[i]].. 0< ar[i] <N
*/

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void pos1info2BruteForce(int arr[], int size){
    int b[size];
    for(int i=0; i<size;i++){
        b[i] = arr[arr[i]];
    }

    printArray(b,size);
}

void pos1info2Optimized(int arr[], int size){

}

int main(){
    int arr[] = {6,4,2,1,7,0,3,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    pos1info2BruteForce(arr,size);
    return 0;
}