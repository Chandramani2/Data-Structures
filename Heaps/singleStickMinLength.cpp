#include "bits/stdc++.h"
using namespace std;

int minCost(vector<int> &arr){

    //Min Heap
    priority_queue<int, vector<int>, greater<int>> minPQ(arr.begin(), arr.end());
    int cost = 0; 
    int ans = 0;
    while(minPQ.size() > 1){
        int minEle1 = minPQ.top();
        minPQ.pop();
        int minEle2 = minPQ.top();
        minPQ.pop();
        cout<<minEle1<<", "<<minEle2<<endl;
        cost = minEle1 + minEle2;
        ans += cost;
        cout<<"Cost: "<<cost<<endl;
        minPQ.push(cost);
    }
    return ans;
}

int main() {
    vector<int> arr = {3,2,7,5};
   
    cout<<"Min Cost: "<<minCost(arr);
    return 0;
}
