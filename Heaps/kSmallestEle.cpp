#include "bits/stdc++.h"
using namespace std;
/*  - Insert all in MinHeap and pop K elements (N*log(N) + K*log(N))
    - sort and get 1st K elements N*log(N) better than 1st method
*/
void kSmallest(vector<int> &arr, int K){
    int tmp = K;
    //Min Heap
    // Method 1: Insert all in MinHeap and pop K elements (N*log(N) + K*log(N))
    priority_queue<int, vector<int>, greater<int>> minPQ(arr.begin(), arr.end());
    while(K>0){
        cout<<minPQ.top()<<" ";
        minPQ.pop();
        K--;
    }

    /* Method 3: Insert first K elements in MaxHeap
        - iterate for remaining elements
        - new element < max ele, delete max ele from the maxPQ
            and add new ele in the maxPQ
    */
    K = tmp;
    priority_queue<int> maxPQ;
    for(int i=0; i<K; i++){
        maxPQ.push(arr[i]);
    }

    for(int i=K; i<arr.size(); i++){
        if(arr[i] < maxPQ.top()){
            maxPQ.pop();
            maxPQ.push(arr[i]);
        }
    }

    // now we left with first K smallest in maxPQ
    cout<<"\n" + to_string(K) + " smallest elements are: ";
    while(maxPQ.size()>0){
        cout<<maxPQ.top()<<" ";
        maxPQ.pop();
    }
}

int main() {
    int K = 4;
    vector<int> arr = {15,9,6,20,25,-3,13,5,25};
    
    cout<<"First " + to_string(K) + " smallest elements are: ";
    kSmallest(arr, K);
    return 0;
}
