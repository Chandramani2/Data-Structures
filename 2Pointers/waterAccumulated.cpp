#include<bits/stdc++.h>
using namespace std;

int totalWaterAccumulated(int arr[], int size){
   int p1 = 1, p2 = size-2;
   int lmax = arr[p1-1];
   int rmax = arr[p2+1];
   int totalWater = 0;
   while(p1<=p2){
    if(lmax < rmax){
        // Add the water for arr[p1]
        totalWater += max(0, lmax - arr[p1]);
        lmax = max(lmax, arr[p1]);
        // Update left pointer p1 as we have 
        // decided water for this
        p1++;
    }
    // If rMax is smaller, then we can 
    // decide the amount of water for arr[right]
    else{
        totalWater += max(0, rmax - arr[p2]);
        rmax = max(rmax, arr[p2]);
        p2--;
    }
   }
   return totalWater;
}

int main(){
    int arr[] = {2, 1, 5, 3, 1, 0, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Total Water Accumulated is: " <<totalWaterAccumulated(arr, size);
 
    return 0;
}