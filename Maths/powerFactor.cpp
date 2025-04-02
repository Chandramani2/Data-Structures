#include<bits/stdc++.h>
using namespace std;
/*
    (A^B)%M
    1. If B is even [(A^(B/2))%M * (A^(B/2))%M]
    2. If B is odd [(A^(B/2))%M * (A^(B/2))%M * A%M]%M
*/

long power(long a, long b, long M){

    if(b==0) return 1;
    if(b==1) return a % M;
    long x = power(a,b/2,M);
    if(b%2==0) return (x*x)%M;
    else return ((x*x)%M * a%M)%M;

}
int main(){
    long a,b,M;
    cin>>a>>b>>M;
    cout<<a<<" "<<b<<" "<<M<<endl;
    cout<<"The value of A to the power B is: "<<power(a,b,M);
    return 0;
}