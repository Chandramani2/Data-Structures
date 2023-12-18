#include<bits/stdc++.h>
using namespace std;

int LCS(string &str1, string &str2, int i, int j, vector<vector<int>> &dp){
	if(i==-1 || j==-1) return 0;
	if(dp[i][j]==-1){
		
		if(str1[i]==str2[j]){
			dp[i][j] = 1 + LCS(str1,str2,i-1,j-1,dp);
		}
		else{
			dp[i][j] = max(LCS(str1,str2,i-1,j,dp), LCS(str1,str2,i,j-1,dp));
		}
	}
	return dp[i][j];
}

// int LCS(string &str1, string &str2, int i, int j, vector<vector<int>> &dp){
// 	if(i==-1 || j==-1) return 0;
	
		
// 	if(str1[i]==str2[j]){
// 		return 1 + LCS(str1,str2,i-1,j-1,dp);
// 	}
// 	else{
// 		return max(LCS(str1,str2,i-1,j,dp), LCS(str1,str2,i,j-1,dp));
// 	}
	
// }

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
				if(i>0 && (dp[i][j]==dp[i-1][j])) i--;
				else j--;
			}
		}
	return ans;
}

int main(){
	string str1 = "KARMATW";
	string str2 = "AWRQMT";
	int n = str1.length();
	int m = str2.length();
	cout<<n<<" "<<m<<endl;
	vector<vector<int>>dp(n,vector<int>(m,-1));
	cout<<LCS(str1,str2, n-1,m-1, dp);
	cout<<endl;
	print2DArray(n,m,dp);
	cout<<endl;
	cout<<printLCSString(str1,str2,dp);
	return 0;
}