#include<bits/stdc++.h>
using namespace std;

void print2DArray(vector<vector<int>> &dp){
	for(int i=0; i < dp.size(); i++){
		for(int j=0; j < dp[0].size(); j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}

int LCS(string &str1, string &str2, int i, int j, vector<vector<int>> &dp){
	if(i==-1 || j==-1) return 0;
	if(dp[i][j]==-1){
		
		if(str1[i]==str2[j]){
			dp[i][j] = 1 + LCS(str1,str2,i-1,j-1,dp);
		}
		else{
			dp[i][j] = max(LCS(str1,str2,i-1,j,dp), 
						   LCS(str1,str2,i,j-1,dp));
		}
	}
	return dp[i][j];
}

int LCSBottomUp(string text1, string text2){
	int m = text1.length();
    int n = text2.length();

    // dp[i][j] will store the length of LCS of text1[0..i-1] and text2[0..j-1]
    // We use a 2D vector initialized to 0.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 1. Build the DP Table (Bottom-Up)
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // If characters match, add 1 to the result of the previous diagonal
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            // If they don't match, take the maximum result from top or left
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
   cout << "\n-----------------\n" << endl;
   print2DArray(dp);
   cout << "\n-----------------\n" << endl;

    // 2. Reconstruct the String (Backtracking)
    // Start from the bottom-right cell and work backwards to find the characters
    string lcs = "";
    int i = m, j = n;
    
    while (i > 0 && j > 0) {
        // If current characters match, they are part of the LCS
        if (text1[i - 1] == text2[j - 1]) {
            lcs += text1[i - 1];
            i--;
            j--;
        }
        // If not, move to the cell with the larger value (up or left)
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // Move up
        } else {
            j--; // Move left
        }
    }

    // The string was built backwards during backtracking, so we reverse it
    reverse(lcs.begin(), lcs.end());
    cout<<"LCS: "<<lcs<<endl;
	return dp[m][n];
}


string printLCSString(string str1, string str2,  vector<vector<int>> &dp){
	int i = dp.size()-1;
	int j = dp[0].size()-1;
	string ans = "";
		while(i>=0 && j>=0){
			if(str1[i]==str2[j]) {
				ans+=str1[i];
				i--;j--;
			}
			// If not, move to the cell with the larger value (up or left)
	        else if (dp[i - 1][j] > dp[i][j - 1]) {
	            i--; // Move up
	        } else {
	            j--; // Move left
	        }
		}
	return ans;
}

int main(){
   	string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
	int n = str1.length();
	int m = str2.length();
	cout<<n<<" "<<m<<endl;
	vector<vector<int>>dp(n,vector<int>(m,-1));
	cout<<"LCSTopDown: "<<LCS(str1,str2, n-1,m-1, dp);
	cout<<"\nLCS: "<<printLCSString(str1,str2,dp);
	cout<<endl;
	cout<<"LCSBottomup: "<<LCSBottomUp(str1,str2);
	cout<<endl;
	print2DArray(dp);
	cout << "\n-----------------\n" << endl;
	
	return 0;
}