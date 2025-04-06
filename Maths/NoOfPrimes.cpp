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

//sieve of eratosthenes
int countPrimesOptimized(int N){
    bool p[N+1];
    fill(p, p+N+1, true);
    p[0] = p[1] = false;

    // for(int i=2; i<=N; i++){
    //     if(p[i]){
    //         we need to move on multiples of i

    //         for(int j=2*i;j<=N;j+=i){
    //             p[j] = false;
    //         }

    //     }
    // }


    /*small optimization
     1. first strike will be done on squares of the number
     2. value of i need not to be iterated over sqrt(N)+1 when j starting value is i*i
    */
    for(int i=2; i*i<=N; i++){
        if(p[i]){
             for(int j=i*i;j<=N;j+=i){
                p[j] = false;
            }
        }
    }
    // Iterate on P Array and check how many True's
    int cnt=0;
    for(int i=0;i<=N;i++){
        if(p[i]) {cnt++;}
    }
    return cnt;
}

int main(){
    int N;
    cin>>N;
    cout<<isPrimeBruteForce(N)<<endl;
    cout<<isPrimeOptimized(N)<<endl;
    cout<<"No. Of Primes from 1 to "<<N<<" is: "<< countPrimesBruteForce(N)<<endl;
    cout<<"No. Of Primes from 1 to "<<N<<" is: "<< countPrimesOptimized(N)<<endl;

    return 0;
}