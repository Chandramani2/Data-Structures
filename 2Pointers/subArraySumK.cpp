#include<bits/stdc++.h>
using namespace std;
/* Take Prefix Sum and check if there exists any 2 elements with DIff K
 pairSUmK.cpp */
/* Note:- Edge Cases
    With above logic, we'll miss all subarray sums starting with 0
    TO solve:-
    1. Add '0' at start of pf[]
    2. Iterate on pf[] and check if one of the element is 'k'
    In this example K=19 (Index sum 0-5)
*/

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void prefixArray(int arr[], int size){
    for(int i=1; i<size; i++){
        arr[i] = arr[i-1] + arr[i];
    }
}

bool pairDiffK(int arr[], int size, int k){
    int p1 = 0, p2 = 1;
    k = abs(k);
    while(p2<size){
        int diff = arr[p2] - arr[p1];
        if(arr[p2] == k) return true;
        if(diff>k){// to find K we have to decrease the sum   
            p1++;
            if(p1==p2) p2++;
        } 
        else if(diff<k) p2++;
        else return true;
    }
    return false;
}

int main(){
    int arr[] = {3,2,5,0,1,8,6,2,10};
    int k = 19;
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
    prefixArray(arr,size);
    printArray(arr,size);
    if(pairDiffK(arr, size, k)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}