#include<bits/stdc++.h>
using namespace std;
// let's consider 3*3 matrix
#define ROWS 3
#define COLS 3

int countAllPaths(int i, int j){
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	int top = countAllPaths(i-1,j);
	int left = countAllPaths(i,j-1);
	return top + left;
}
int main(){
	
	cout<<"TotalUniquePaths: "<<countAllPaths(ROWS,COLS);
	return 0;
}