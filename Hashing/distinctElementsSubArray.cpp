#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void printVector(vector<int>arr){
    for(auto x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

/*count distinct elements in every subarray
O/P:-       1 2 2 3 3 4 
            1 1 2 3 4 
            1 2 3 4 
            1 2 3 
            1 2 
            1 
*/
void distinctEleSubArrayNaive(int arr[], int size){
    vector<int> cntAns;
    unordered_map<int,int> hm;
    for(int i=0; i<size; i++){\
        cntAns.clear();
        hm.insert({arr[i], i});
        int cnt = 1;
        for(int j=i; j<size; j++){
            if(hm.find(arr[j])==hm.end()){
                cnt++;
                hm.insert({arr[j], i});
            }
            cntAns.push_back(cnt);  
        }
         printVector(cntAns);
         hm.clear();
    }
}

void distinctEleSubArrayOptimized(int arr[], int size){
    vector<int> cntAns;
    for(int i=0; i<size;i++){
       unordered_set<int>hs;
        for(int j=i; j<size; j++){
            hs.insert(arr[j]);
            cout<<hs.size()<<" ";
        }
            cout<<endl;
    }
}


int main(){
    int arr[] = {3,2,2,7,3,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Naive: \n";
    distinctEleSubArrayNaive(arr,size);
    cout<<"\nOptimized: \n";
    distinctEleSubArrayOptimized(arr,size);

    return 0;
}