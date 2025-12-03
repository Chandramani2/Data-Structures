#include "bits/stdc++.h"
using namespace std;

// Recursion
int fib(int N){
	if(N==0) return 0;
	if(N==1) return 1;
	return fib(N-1) + fib(N-2);
}
/* DP
	- solving problem using substructure
	- fib(N) = fib(N-1) + fib(N-2) // Optimal substructure
	- overlapping subproblem
*/
// Tabulization
int fibBottomUp(int N){    // FIB[i] -> ith Fibonacci Number: Dp State
	int FIB[N+1]; // DP Table
	FIB[0] = 0; FIB[1] = 1; // Base Conditions
	for(int i=2; i<=N; i++){
		FIB[i] = FIB[i-1] + FIB[i-2]; // Dp Expression
	}
	return FIB[N];
}

// Memoization
int fibTopDown(int N, vector<int> &FIB){
	if(N==0) return 0;
	if(N==1) return 1;
	if(FIB[N] == -1){
		FIB[N] = fibTopDown(N-1, FIB) + fibTopDown(N-2, FIB);
	}
	return FIB[N];
}

// Space Optimization DP
int fibSpaceOptimization(int N){
	// at any point, we need 3 states (i,i-1,i-2), we can store in 3 variables
	int a=0, b=1;
	int curr = 0;
	for(int i=2; i<=N; i++){
		curr = a+b;
		a = b;
		b = curr;
	}
	return curr;
}

int main()
{	int N = 8;
	cout<<"Recursion: "<<fib(N);
	cout<<"\nDP: BottomUp: "<<fibBottomUp(N);
	vector<int>FIB(N+1, -1); // DP Table
	cout<<"\nDP: TopDown: "<<fibTopDown(N, FIB);
	cout<<"\nDP: SpaceOptimization: "<<fibSpaceOptimization(N);

	return 0;
}
