#include "bits/stdc++.h"
using namespace std;
/* How many ways we can reach from stair 0 -> stair N
	stair i -> (i+1, i+2)
*/
// Recursion
int NStairs(int N){
	if(N==0) return 0;
	if(N==1) return 1;
	return NStairs(N-1) + NStairs(N-2);
}
/* DP
	- number of ways to reach i'th step
	- NStairs(i) = NStairs(i-1) + NStairs(i-2) // Optimal substructure
	- overlapping subproblem
*/
// Tabulization
int NStairsBottomUp(int N){    // STAIRS[i] -> ith stairs: Dp State
	int STAIRS[N+1]; // DP Table
	STAIRS[0] = 0; STAIRS[1] = 1; // Base Conditions
	for(int i=2; i<=N; i++){
		STAIRS[i] = STAIRS[i-1] + STAIRS[i-2]; // Dp Expression
	}
	return STAIRS[N];
}

// Memoization
int NStairsTopDown(int N, vector<int> &stairs){
	if(N==0) return 0;
	if(N==1) return 1;
	if(stairs[N] == -1){
		stairs[N] = NStairsTopDown(N-1, stairs) + NStairsTopDown(N-2, stairs);
	}
	return stairs[N];
}

// Space Optimization DP
int NStairsSpaceOptimization(int N){
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
	cout<<"Recursion: "<<NStairs(N);
	cout<<"\nDP: BottomUp: "<<NStairsBottomUp(N);
	vector<int>stairs(N+1, -1); // DP Table
	cout<<"\nDP: TopDown: "<<NStairsTopDown(N, stairs);
	cout<<"\nDP: SpaceOptimization: "<<NStairsSpaceOptimization(N);

	return 0;
}
