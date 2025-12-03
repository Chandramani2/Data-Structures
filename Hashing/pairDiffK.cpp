#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}
// Have to Sort First for using 2 Pointers
bool pairDiffK(int arr[], int size, int k){
    sort(arr,arr+size);
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

// If the Array is Not Sorted we can use Hashing to optimize time
bool pairDiffKHashingNaive(int arr[], int size, int k){
    unordered_map<int, int> hm;
    for(int i=0; i<size; i++){
        hm.insert({arr[i], hm[arr[i]]++});
    }
   for(int i=0; i<size; i++){
        int a = arr[i];
        int b = a - k;
        //search b in entire array
        if(hm.find(b)!=hm.end()) return true;
        else{
            hm[arr[i]]++;
        }
   }

   return false;
}
// If the Array is Not Sorted we can use Hashing to optimize time
bool pairDiffKHashingOptimized(int arr[], int size, int k){
    unordered_map<int, int> hm;
    for(int i=0; i<size; i++){
        int a = arr[i];
        int b = a - k;
        //search b in entire array
        if(hm.find(b)!=hm.end()) return true;
        else hm.insert({a, hm[a]++});    
    }
    return false;
}

int main(){
    int arr[] = {3,6,-1,3,2,9,7,7,2,3,11};
    int k = 5;
    int size = sizeof(arr)/sizeof(arr[0]);
    if(pairDiffKHashingNaive(arr, size, k)){
        cout<<"NaiveHashing: True\n";
    }
    else{
        cout<<"NaiveHashing: False\n";
    }
     if(pairDiffKHashingOptimized(arr, size, k)){
        cout<<"OptimizedHashing: True\n";
    }
    else{
        cout<<"OptimizedHashing: False\n";
    }
    if(pairDiffK(arr, size, k)){
        cout<<"2pointers: True\n";
    }
    else{
        cout<<"2pointers: False\n";
    }
    
       return 0;
}