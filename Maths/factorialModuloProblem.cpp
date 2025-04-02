#include<bits/stdc++.h>
using namespace std;
/*
    Given A,B,P calculate (A^(B!))%P

    A=7, B=1000, P=31(Prime Number)
    Issues:
    1. Cannot store 1000!
    2. Cannot Take modulus over Power
    A/C to fermat's theorem:
    (7^30)%31 = 1 ------  (a^p-1) = 1 mod p
    ((7^30) * (7^30))%31 = 1
    (7^30*n)%31 = 1
    1000! = (30*X) + R(remainder)
    R = (1000!)%30
*/
long power(long a, long b, long M){

    if(b==0) return 1;
    if(b==1) return a % M;
    long x = power(a,b/2,M);
    if(b%2==0) return (x*x)%M;
    else return ((x*x)%M * a%M)%M;

}

long calculateFactorial(long b, long P){
    long ans=1;
    for(int i=1;i<=b;i++){
        ans=(ans*i)%(P-1);
    }
    return ans;
}

long calculateProblem(long a, long b, long P){
    return power(a,calculateFactorial(b,P),P)%(P-1);
}

int main(){
    long A,B,P;
    cin>>A>>B>>P;
    cout<<A<<" "<<B<<" "<<P<<endl;
    cout<< "(" << A << "^(" << B << "!))%" << P << " = " << calculateProblem(A,B,P)<<endl;
    return 0;
}