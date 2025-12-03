#include<bits/stdc++.h>
using namespace std;
/* count UNIQUE Pairs a-b = k */

void printUniquePairs(vector<pair<int,int>> ansPairs){
    for(auto x: ansPairs){
        cout<<"(" + to_string(x.first) + "," + to_string(x.second) + ") ";
    }
    cout<<endl;
}
// Iterate on Hashset instead of Array to avoid duplicate count
int pairDiffKHashing(int arr[], int size, int k){
    int cnt=0;
    set<int> hs;
    vector<pair<int,int>> ansPairs;
    for(int i=0; i<size; i++){
        hs.insert(arr[i]);
    } 
    for(auto a: hs){
        int b = a - k;
        if(hs.find(b)!=hs.end()) {
            cnt++;
            //store Pairs
            ansPairs.push_back({a,b});
        }
    }
   printUniquePairs(ansPairs);
   return cnt;
}


int main(){
    int arr[] = {3,6,-1,3,2,9,7,7,2,3,11};
    int k = 5;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<" Count of Unique Pairs such that (a-b) = k is:"<<pairDiffKHashing(arr,size,k);
   
    
    return 0;
}