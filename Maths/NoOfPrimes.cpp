#include<bits/stdc++.h>
using namespace std;

bool isPrimeBruteForce(int N){
    for(int i=2;i<N;i++){
        if(N%i==0){
             return false;
        }
    }
    return true;
}

bool isPrimeOptimized(int N){
    for(int i=2;i*i<=N;i++){
        if(N%i==0){
             return false;
        }
    }
    return true;
}

/* Count Number of Primes From 1-N */

int countPrimesBruteForce(int N){
    int cnt=0;
    for(int i=2;i<=N;i++){
        if(isPrimeOptimized(i)){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int N;
    cin>>N;
    cout<<isPrimeBruteForce(N)<<endl;
    cout<<isPrimeOptimized(N)<<endl;
    cout<<"No. Of Primes from 1 to "<<N<<" is: "<< countPrimesBruteForce(N)<<endl;
    return 0;
}