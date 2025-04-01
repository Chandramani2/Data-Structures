#include<bits/stdc++.h>
using namespace std;
/*
    eg1-> 1,2,3,4 ==> 1,2,4,3
    eg2-> 1,3,2 ==> 2,1,3
    eg3-> 4,3,2 ==> 4,3,2
    eg4-> 8,10,7,6,5 ==> 10,5,6,7,8
    eg5-> 7,12,9,4,2,-1 ==> 9,-1,2,4,7,12
    eg6-> 9,18,15,12,10,6,4,2,0 ==> 10,0,2,4,6,9,12,15,18
    eg7 -> 3,5,11,7,20,18,14,10,6,3,1 ==> 3,5,11,10,1,3,6,7,14,18,20
    Observation:
    1. From last all the elements should be in increasing order
    2. As soon the pattern breaks, swap the smaller element found with the next greater element
    3. reverse the array after the index[i+1] where you have found the smaller element

*/
void rotateArray(int arr[], int size, int L, int R){
    while(L<=R){
        int tmp = arr[L];
        arr[L] = arr[R];
        arr[R] = tmp;
        L++; R--;
    }
}

void nextPermutation(int arr[], int size){
    int i;
    for(i = size-2; i>=0; i--){
        if(arr[i] < arr[i+1]){
            break;
        }
    }
    if(i==-1) return; // If all the elements are already in decresing order then return
    // Now We have to find Next Greater Element so that we can swap
    // Iterate from the back and get First Greater element
    for(int j=size-1; j>=0; j--){
        if(arr[j]>arr[i]){
            swap(arr[j],arr[i]);
            break;
        }
    }
    // Now Reverse the Array
    rotateArray(arr,size,i+1,size-1);

}

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    nextPermutation(arr,size);
    printArray(arr,size);
    return 0;
}