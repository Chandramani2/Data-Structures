#include<bits/stdc++.h>
using namespace std;
// let's consider 4*3 matrix
#define ROWS 4
#define COLS 3

int countAllPaths(int i, int j){
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	int top = countAllPaths(i-1,j);
	int left = countAllPaths(i,j-1);
	return top + left;
}

int countPathsMatrix(int R, int C){
	int dp[R][C];
	fill(dp[0],dp[0]+C,1); //fill 0th row
	for(int i=0; i<R; i++){
		dp[i][0] = 1; //fill 0th column
	}

	for(int i=1; i<R; i++){
		for(int j=1; j<C; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	return dp[R-1][C-1];
}

// At max we need 2 Rows
int countPathsMatrixSpaceOpt(int R, int C){
	int dp[2][C];
	fill(dp[0],dp[0]+C, 1); //fill 0th row

	for(int i=1; i<R; i++){
		dp[i%2][0] = 1; // fill 1st column
		for(int j=1; j<C; j++){
			dp[i%2][j] = dp[(i-1)%2][j] + dp[i%2][j-1];
		}
	}
	return dp[(R-1)%2][C-1];
}

int main(){
	
	cout<<"TotalUniquePaths: "<<countAllPaths(ROWS-1,COLS-1);
	cout<<"\nTotalUniquePaths DP: "<<countPathsMatrix(ROWS,COLS);
	cout<<"\nTotalUniquePaths DP Space Optimized: "<<countPathsMatrixSpaceOpt(ROWS,COLS);


	return 0;
}