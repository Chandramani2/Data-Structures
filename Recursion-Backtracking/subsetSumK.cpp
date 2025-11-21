#include<bits/stdc++.h>
using namespace std;

// Q1. Is subset Sum K present
bool subsetSum(int i, int size, int sum, int k, int arr[]){
    if(i==size) return sum==k;
    bool x1,x2;
    sum+=arr[i];
    x1 = subsetSum(i+1,size,sum,k,arr);
    sum-=arr[i];
    x2 = subsetSum(i+1,size,sum,k,arr);
    return (x1||x2);
    //2nd method:
    // return (subsetSum(i+1,size,sum+arr[i],k,arr) ||  // -> pick
    //         subsetSum(i+1,size,sum,k,arr));          // -> Not pick
}

//Q2. Number of SubsetSum = K
int NumberOfSubsetSumK(int i, int size, int sum, int k, int arr[]){
    if(i==size) {
        if(sum==k) {return 1;}
        return 0;
    }
    return (NumberOfSubsetSumK(i+1,size,sum+arr[i],k,arr) +  // -> pick
            NumberOfSubsetSumK(i+1,size,sum,k,arr));          // -> Not pick
}

/* Q3. Numbers can be picked multiple times
        Given All +ve Array Elements, otherwise it'll go in infinite loop
*/
int NumberOfSubsetSumKRepeating(int i, int size, int sum, int k, int arr[]){
    if(sum>k) return 0;
    if(i==size) return sum==k;
       
    return (NumberOfSubsetSumKRepeating(i,size,sum+arr[i],k,arr) +  // -> pick
            NumberOfSubsetSumKRepeating(i+1,size,sum,k,arr)); // -> Not pick
}

void subsetSumK(int arr[], int size, int k){
    // Q1. Is subset Sum K present
    int i=0, sum=0;
    bool isSumK = subsetSum(i,size,sum,k,arr);
    if(isSumK) cout<<"Found";
    else cout<<"Not Found";

    //Q2. Number of SubsetSum = K
    i=0;sum=0;
    cout<<"\nNumber of subset sum = " + to_string(k) + ": "
    <<NumberOfSubsetSumK(i,size,sum,k,arr);

    /* Q3. Numbers can be picked multiple times
        Given All +ve Array Elements, otherwise it'll go in infinite loop
    */
    i=0;sum=0;
    cout<<"\nNumber of subset sum Repeating = " + to_string(k) + ": "
    <<NumberOfSubsetSumKRepeating(i,size,sum,k,arr);
}

int main(){
    int arr[] = {5,2,9,8,3,4,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 7;
    subsetSumK(arr,size,k);
    return 0;
}