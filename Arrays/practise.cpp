#include "bits/stdc++.h"
using namespace std;

int fib(int N){
    if(N==0) return 0;
    if(N==1) return 1;
    return fib(N-1) + fib(N-2);
}
int main()
{
    cout<<fib(5);
    return 0;
}
