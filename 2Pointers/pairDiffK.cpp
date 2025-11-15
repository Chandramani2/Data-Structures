#include<bits/stdc++.h>
using namespace std;

bool pairDiffK(int arr[], int size, int k){
    int p1 = 0, p2 = 1;
    k = abs(k);
    while(p2<size){
        int diff = arr[p2] - arr[p1];
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
    int arr[] = {-3,0,1,3,6,7,11,14,18,25};
    int k = 17;
    int size = sizeof(arr)/sizeof(arr[0]);
    if(pairDiffK(arr, size, k)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
       return 0;
}