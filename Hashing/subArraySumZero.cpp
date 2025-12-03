#include<bits/stdc++.h>
using namespace std;
/* count UNIQUE Pairs a-b = k */

void printUniquePairs(vector<pair<int,int>> ansPairs){
    for(auto x: ansPairs){
        cout<<"(" + to_string(x.first) + "," + to_string(x.second) + ") ";
    }
    cout<<endl;
}

void makePrefixArray(int arr[], int size){
    for(int i=1; i<size; i++){
        arr[i] = arr[i] + arr[i-1];
    }
}
// Iterate on Hashset instead of Array to avoid duplicate count
bool subArraySumZero(int arr[], int size){
    makePrefixArray(arr,size);
    set<int> hs;
    for(int i=0; i<size; i++){
        hs.insert(arr[i]);
    } 
    if(hs.size() < size) return true;
    if(hs.find(0)!=hs.end()) return true;
    return false;
}

//Prefix Array already made in above function
void subArraySumZeroPairs(int arr[], int size){
    unordered_map<int, int> hm;
    vector<pair<int, int>> ansPairs;
    for(int i=0; i<size; i++){
        if(hm.find(arr[i])!= hm.end()){
            ansPairs.push_back({hm[arr[i]], i});
        }
        if(hm.find(0)!= hm.end()){
            ansPairs.push_back({hm[arr[i]], i});
        }
        else hm.insert({arr[i], i+1});
    }
    printUniquePairs(ansPairs);
}

int main(){
    int arr[] = {2,2,1,-3,4,3,1,-2,-3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"is subarray sum zero present :"<<subArraySumZero(arr,size);
    cout<<"\nPairs are: \n";
    subArraySumZeroPairs(arr,size);
    return 0;
}