#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void bruteForceRangeSubArraySumZero(int arr[], int size){
    for(int L=0; L<size; L++){
        for(int R=L; R<size; R++){
            int sum=0;
            for(int i = L; i<=R; i++){
                sum+=arr[i];
            }
            if(sum==0){
                cout<<L<<" "<< R << endl;
            }
        }
    }
}

void makePrefixArray(int arr[], int size, int pf[]){
    pf[0] = arr[0];
    for(int i=1;i<size;i++){
        pf[i] = arr[i] + pf[i-1];
    }
}

string checkSubArraySumZero(int arr[], int pf[], int size){
    set<int>hs;
    for(int i=0; i<size; i++){
        hs.insert(pf[i]);
    }
    if(hs.size()!=size) return "true";
    return "false";
}

int main(){
    int arr[] = {2,1,0,1,-2,3,4,-1,2,-6,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    bruteForceRangeSubArraySumZero(arr, size);

    int pf[size] = {0};
    makePrefixArray(arr, size, pf);
    printArray(pf,size);
    cout<<"Is SubArraySumZero Present: "<< checkSubArraySumZero(arr,pf,size);
    return 0;
}