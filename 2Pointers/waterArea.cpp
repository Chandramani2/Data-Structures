#include<bits/stdc++.h>
using namespace std;
/*  Find Maximum Area Accumulated between any two buildings
    This problem is different from Water Accumulated over the building
*/
int totalWaterArea(int arr[], int size){
   int p1 = 0, p2 = size-1;
   int maxWaterArea = 0;
    //we'll move the pointer who have minimum array value
   // we're moving those pointer because we cannot get better answer i.e. max area
   while(p1<=p2){
    int area = min(arr[p1], arr[p2]) * (p2-p1);
    maxWaterArea = max(maxWaterArea, area);
    if(arr[p1] < arr[p2]) p1++;
    else p2--;
   }
   return maxWaterArea;
}

int main(){
    int arr[] = {3,5,4,7,3,6,5,4,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Max Water Area Between any 2 Building are: " <<totalWaterArea(arr, size);
 
    return 0;
}