#include<bits/stdc++.h>
using namespace std;
/*
    (a^p-1) = 1 mod p ----- p is a prime number
    multiply a^-1 both sides
    (a^(p-2)) = a^(-1)(mod p) ------ Fermat's little Theorem for Inverse Modulo
    (a^(p-2))%p = (a^-1)%p
*/
long power(long a, long b, long M){

    if(b==0) return 1;
    if(b==1) return a % M;
    long x = power(a,b/2,M);
    if(b%2==0) return (x*x)%M;
    else return ((x*x)%M * a%M)%M;

}

long fermatTheorem(int a, int b, int p){
    return power(a,p-2,p);
}
int main(){
    int a,b,p;
    cin>>a>>b>>p;
    cout<<fermatTheorem(a,b,p)<<endl;
    return 0;
}