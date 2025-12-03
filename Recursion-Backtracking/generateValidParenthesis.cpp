
#include<bits/stdc++.h>
using namespace std;
/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 */

void printVector(vector<int> arr){
	for(auto x: arr) cout<<x<<", ";
	cout<<endl;
}

//Optimized Method
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



// Naive Method [O^2N * 2N]
// void validParenthesisNaive(int i, int size, vector<string> &arr){
// 	if(i==2*size){
// 		if(!isValidParenthesis(arr)) {
// 			arr.pop(); return;
// 		}
// 		printVector(arr);
// 		return;
// 	}
// 	arr[i] = '(';
// 	validParenthesisNaive(i+1,size,arr);
// 	arr[i] = ')';
// 	validParenthesisNaive(i+1,size,arr);
// }

int main(){
	int n=4;
	vector<string>ans;
	string curr = "";
	generateValidParenthesis(0,n,0,0,ans, curr);
	printVector(ans);
	
	// vector<string>arr;
	// validParenthesisNaive(0,n,arr);
	return 0;
}