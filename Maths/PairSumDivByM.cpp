#include<bits/stdc++.h>
using namespace std;
/*
Given N array Elements, calculate no. of pair sum divisible by M
*/

int PairSumDivByMBruteForce(int arr[], int size, int M){
    int cnt = 0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if((arr[i]+arr[j])%M == 0) {
                cnt++;
            }
        }
    }

    return cnt;
}

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}
int factorial(int N){
    int ans=1;
    for(int i=1;i<=N;i++){
        ans=ans*i;
    }
    return ans;
}

int combination(int N){
    return factorial(N)/(factorial(2)*factorial(N-2));
}

int PairSumDivByMOptimized(int arr[], int size, int M){
    int cnt[size]={0};
    for(int i=0;i<size;i++){
        cnt[arr[i]%M]++;
    }
    printArray(cnt,size);

    int i=0, j=size-1, ans=0;
    while(i<j){
        int count = cnt[i]+cnt[j];
        ans=ans+combination(count);
        i++;j--;
    }
    return ans;
}


int main(){
    int arr[] = {7,2,5,4,6,3,13,26,14,18,15,30,35};
    int M = 10;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"No. Of Pair Sum Divisible By "<<M<<": "<< PairSumDivByMBruteForce(arr,size,M)<<endl;
    cout<<"No. Of Pair Sum Divisible By "<<M<<": "<< PairSumDivByMOptimized(arr,size,M)<<endl;
    return 0;
}