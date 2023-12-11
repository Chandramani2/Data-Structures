/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 */

#include<bits/stdc++.h>
using namespace std;

void generateValidParenthesis(int ind, int n, int co, int cc, vector<string> &ans, string curr){
	
	if(ind>=2*n){
		ans.push_back(curr);
		return;
	}
	
	if(co<n){
		curr+='(';
		generateValidParenthesis(ind+1,n,co+1,cc, ans,curr);
		curr.pop_back();
	}
	if(cc<co ){
		curr+=')';
		generateValidParenthesis(ind+1,n,co,cc+1, ans,curr);
		curr.pop_back();
	}
	
}


int main(){
	int n=4;
	vector<string>ans;
	string curr = "";
	generateValidParenthesis(0,n,0,0,ans, curr);
	
	for(auto x: ans){
		cout<<x<<endl;
	}
	return 0;
}