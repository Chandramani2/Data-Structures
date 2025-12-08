#include<bits/stdc++.h>
using namespace std;

int LCS(string &str1, string &str2, int i, int j, vector<vector<int>> &dp, int count){
	if(i==-1 || j==-1) return 0;

	if(str1[i]==str2[j]){
		dp[i][j] =  LCS(str1,str2,i-1,j-1, dp, count+1);
	}
	else{
		dp[i][j] = max(count, max(LCS(str1,str2,i,j-1,dp,0), 
								LCS(str1,str2,i-1,j,dp,0)));
	}
	count = max(count,dp[i][j]);
	return count;
}

void print2DArray(int n, int m, vector<vector<int>> &dp){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
string printLCSString(string str1, string str2,  vector<vector<int>> &dp){
	int i = dp.size()-1;
	int j = dp[0].size()-1;
	string ans = "";
		while(i>=0 && j>=0){
			if(str1[i]==str2[j]) {
				cout<<str1[i]<<" "<<str2[j]<<endl;
				ans+=str1[i];
				i--;j--;
			}
			else{
				i--;j--;

			}
		}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	string str1 = "sadqwertydas";
	string str2 = "jhkqwertyhjk";
	int n = str1.size();
	int m = str2.size();
	int count = 0;
	vector<vector<int>>dp(n,vector<int>(m,0));
	// cout<<LCS(str1, str2, n-1,m-1, count);
	// print2DArray(n,m,dp);
	cout<<LCS(str1, str2, n-1,m-1,dp, count);
	cout<<endl;
	print2DArray(n,m,dp);
	cout<<endl;
	cout<<printLCSString(str1,str2,dp);
	return 0;
}