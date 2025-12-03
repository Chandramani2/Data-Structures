#include<bits/stdc++.h>
using namespace std;

int sumFirstN(int N){
    if(N==0) return 0;
    return sumFirstN(N-1) + N;
}

//BottomUp Approach
int sumFirstNBottomUp(int N){
    int dp[N+1];
    fill(dp,dp+N+1,0);
    for(int i=1;i<=N;i++){
        dp[i] = dp[i-1] + i;
    }
    return dp[N];
}

//Top-Down Approach
int sumFirstNTopDown(int N, int dp[]){
    if(N==0) return 0;
    if(dp[N]!=-1) return dp[N];
    return dp[N] = sumFirstNTopDown(N-1,dp) + N;
}

int main(){
    int N=100;
    cout<<"Recursion: sum of First " + to_string(N) + " Numbers are: "
    <<sumFirstN(N)<<endl;
    
    cout<<"\nDP: sum of First " + to_string(N) + " Numbers are: "
    <<sumFirstNBottomUp(N)<<endl;

    int dp[N+1];
    fill(dp,dp+N+1,-1);
    // vector<int> dp(N + 1, -1);
    cout<<"\nDP: sum of First " + to_string(N) + " Numbers are: "
    <<sumFirstNTopDown(N,dp)<<endl;

    cout<<"\n Ask any First X numbers sum between 1 to N: "
    <<dp[30];
    return 0;
}