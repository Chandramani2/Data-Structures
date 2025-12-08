#include<bits/stdc++.h>
using namespace std;

int editDistance(string &str1, string &str2, int i , int j){
	if(i==0) return j;
	if(j==0) return i;
	if(str1[i]==str2[j]) return editDistance(str1,str2, i-1,j-1);
	else{
		// Insert last char of s2 in s1 // Replace last char of s2 in s1 // delete last of s1 
		return 1 + min(editDistance(str1,str2, i,j-1), min(editDistance(str1,str2, i-1,j-1), editDistance(str1,str2, i-1,j)));
	}
}

int editDistance(string &str1, string &str2, int i , int j, vector<vector<int>> &dp){
	if(i==0) return j;
	if(j==0) return i;
	if(dp[i][j]!=-1) return dp[i][j];
	if(str1[i]==str2[j]) 
		return dp[i][j] = editDistance(str1,str2, i-1,j-1);
	else{
		// Insert last char of s2 in s1 // Replace last char of s2 in s1 // delete last of s1 
		return dp[i][j] = 1 + min(editDistance(str1,str2, i,j-1), 
							min(editDistance(str1,str2, i-1,j-1), 
								editDistance(str1,str2, i-1,j)));
	}
}

int main(){
	string str1 = "sunday";
	string str2 = "saturday";
	int n = str1.length();
	int m = str2.length();
	cout<<"Edit Distance: "<< editDistance(str1, str2, n-1, m-1)<<endl; 

	vector<vector<int>> dp(n,vector<int>(m,-1));
	cout<<"Edit Distance: "<< editDistance(str1, str2, n-1, m-1, dp); 
	return 0;
}