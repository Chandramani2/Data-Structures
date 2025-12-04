#include "bits/stdc++.h"
using namespace std;
/* Given Dice, find No. of ways you can get required sum
*/

/* DP
	- Dp[i] = number of ways we can get sum i  // dp state
	- Dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]  // Optimal substructure
	- overlapping subproblem
*/

// Tabulation (Bottom-Up DP)
int diceSum(int N){    
	int dp[N+1]; // DP Table
	fill(dp, dp+N+1, 0);
	dp[0] = 1;  // Base Conditions
	for(int i=1; i<=N; i++){
		for(int j=1; j<=6; j++){
			if(i>=j){
				dp[i] += dp[i-j]; // Dp Expression
			}
		}
		
	}
	return dp[N];
}

void printDiceCombinations(int target, vector<int> &current, vector<vector<int>> &result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = 1; i <= 6 && i <= target; i++) {
        current.push_back(i);
        printDiceCombinations(target - i, current, result);
        current.pop_back();
    }
}

void printAllDiceCombinations(int N) {
    vector<vector<int>> result;
    vector<int> current;
    printDiceCombinations(N, current, result);
    for (auto &way : result) {
        for (int num : way) {
            cout << num << " ";
        }
        cout << endl;
    }
}
/* O/P:-
		DP: BottomUp: 8
		All ways to get sum 4:
		1 1 1 1 
		1 1 2 
		1 2 1 
		1 3 
		2 1 1 
		2 2 
		3 1 
		4
*/
int main()
{	int N = 4;
	cout<<"DP: BottomUp: "<<diceSum(N);
	cout << "\nAll ways to get sum " << N << ":\n";
    printAllDiceCombinations(N);
	return 0;
}
