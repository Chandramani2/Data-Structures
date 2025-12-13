
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

void printVector(vector<string> arr){
	for(auto x: arr) cout<<x<<", ";
	cout<<endl;
}

void printString(string arr){
	cout<<arr<<endl;
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

// Function to check if parentheses are balanced
bool isBalanced(string expr) {
    stack<char> s;

    for (char x : expr) {
        // 1. If it's an opening bracket, push to stack
        if (x == '(' || x == '[' || x == '{') {
            s.push(x);
            continue;
        }

        // 2. If it's a closing bracket, check stack status
        if (s.empty()) {
            return false; // Found a closing bracket without a pair
        }

        // Check the top of the stack for the matching opening bracket
        char top = s.top();
        
        switch (x) {
            case ')':
                if (top == '{' || top == '[') return false;
                break;
            case '}':
                if (top == '(' || top == '[') return false;
                break;
            case ']':
                if (top == '(' || top == '{') return false;
                break;
            default:
                // Ignore non-bracket characters
                continue; 
        }

        // If matched, remove the opening bracket from the stack
        s.pop(); 
    }

    // 3. If stack is empty, all brackets were matched correctly
    return s.empty();
}

// Helper: Reusing the standard logic to check balance
bool isBalanced2(const string &s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false; // More closing than opening
    }
    return balance == 0;
}


// Naive Method [O^2N * 2N]
// size: number of PAIRS (e.g., 3 pairs = length 6)
// current: the string being built
void validParenthesisNaive(int size, string &current) {
    // Base Case: If string length equals 2 * size
    if (current.length() == 2 * size) {
        if (isBalanced(current)) {
            printString(current);
        }
        return;
    }

    // Recursive Step 1: Add '('
    current.push_back('(');
    validParenthesisNaive(size, current);
    current.pop_back(); // Backtrack: Remove '(' to try ')'

    // Recursive Step 2: Add ')'
    current.push_back(')');
    validParenthesisNaive(size, current);
    current.pop_back(); // Backtrack: Remove ')' to go up the tree
}

int main(){
	int n=3;
	vector<string>ans;
	string curr = "";
	generateValidParenthesis(0,n,0,0,ans, curr);
	printVector(ans);
	
	cout<<"\nMethod 2: "<<endl;
	string str="";
	validParenthesisNaive(n,str);
	return 0;
}