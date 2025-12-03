#include "bits/stdc++.h"
using namespace std;
/* Given N person's, a person wants to stay alone or get involve with another person
 	- No. of ways we can pair all persons
*/
// Recursion
int NPersons(int N){
	if(N==0 || N==1) return 1;
	if(N==2) return 2;
	return NPersons(N-1) + (N-1)*NPersons(N-2);
}
/* DP
	- Dp[i] = number of ways we can pair i person // dp state
	- Dp[i] = dp[i-1] + (i-1)*Dp[i-2] +  // Optimal substructure
	- overlapping subproblem
	: ith person - if left alone, (i-1) people remaining =  dp[i-1]
	: ith can be paired with remaining
		Pairing: 1 & i: Remaining: i-2 = dp[i-2]
		Pairing: 2 & i:	Remaining: i-2 = dp[i-2]
		.
		.
		Pairing: i-1 & i:	Remaining: i-2 = dp[i-2]
		= (i-1)dp[i-2]
*/

// Tabulation (Bottom-Up DP)
int NPersonsBottomUp(int N){    
	int dp[N+1]; // DP Table
	dp[0] = 1; dp[1] = 1; dp[2] = 2; // Base Conditions
	for(int i=3; i<=N; i++){
		dp[i] = dp[i-1] + (i-1)*dp[i-2]; // Dp Expression
	}
	return dp[N];
}

// Memoization (Top-Down DP)
int NPersonsTopDown(int N, vector<int> &persons){
	if(N==0 || N==1) return 1;
	if(N==2) return 2;
	if(persons[N] == -1){
		persons[N] = NPersonsTopDown(N-1, persons) + (N-1)*NPersonsTopDown(N-2, persons);
	}
	return persons[N];
}

// Space-Optimized DP (Tabulation with O(1) space)
int NPersonsSpaceOptimization(int N) {
    if (N <= 1) return 1;
    int a = 1; // dp[i-2]
    int b = 1; // dp[i-1]
    int curr = 1;
    for (int i = 2; i <= N; i++) {
        curr = b + (i - 1) * a;
        a = b;
        b = curr;
    }
    return curr;
}

int main()
{	int N = 8;
	cout<<"Recursion: "<<NPersons(N);
	cout<<"\nDP: BottomUp: "<<NPersonsBottomUp(N);
	vector<int>persons(N+1, -1); // DP Table
	cout<<"\nDP: TopDown: "<<NPersonsTopDown(N, persons);
	cout<<"\nDP: SpaceOptimization: "<<NPersonsSpaceOptimization(N);

	return 0;
}
