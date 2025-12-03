#include<bits/stdc++.h>
using namespace std;
/*  Given a binary String of 0's,1's, at max we can swap 1 position
    find max no. of 1's we can get
    Edge case
    check extra 1's is there or not
        - If there is extra 1's in any part of the array = b-a-1
        - If there is no extra 1 = b-a-2
        Here a & b is 0 array values
*/
int max1s(int arr[], int size){
   //Let's store 0th index position in an array
    vector<int> zeroThIndex;
    for(int i=0 ;i<size; i++){
        if(!arr[i]) // arr[i]==0
            zeroThIndex.push_back(i);
    }
    // So, between alternative indices there will be one zero
    int ans = 0; // max number of 1's
    auto it1 = zeroThIndex.begin();
    for(it1;it1!=zeroThIndex.end();it1++){
        auto it2 = it1+2;
        if(it2<zeroThIndex.end()-1){
            ans = max(ans, *it2-*it1-1); //In between only one zero
        }
        else{
            ans = max(ans, size - *it1);
        }
    }
    return ans;
}

int main(){
    /* In this case Answer is 6 - Index (0,5)
        we can make 0 at index 2 -> 1, 
        becuz there are more 1's in other part of the array like (6,size-1)
        we can pick any 1 and swap with 0 at index 2
    */
    int arr[] = {1,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,0,1,1,0,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Max 1's possible: " <<max1s(arr, size);
 
    return 0;
}