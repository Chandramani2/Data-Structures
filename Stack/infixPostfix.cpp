#include<bits/stdc++.h>
using namespace std;
/* We need a stack, let's name st & we need answer string postfix
	- if we get an operands(variables) directly add in postfix
	- if we get an '(' directly addd in stack
	- if we get an ')', pop elements from stack until you get top element
		of stack has '(' and add them to postfix. delete the '(' from stack
	- if we get an operator directly push it in the stack
		case: if operator we are about to push has a higher presedence
				than operator at top of stack
			else: pop element from top of sstack and add it to postfix, once again check the condition
*/

// Function to return precedence of operators
int precedence(char op) {
    if(op == '+'||op == '-') return 1;
    if(op == '*'||op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

string infixToPostFix(string exp){
	stack<char> st;
	string postfix;
	int n = exp.length();
	for(int i=0; i<n; i++){
		char ch = exp[i];
		// if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
		// 	postfix+=ch;
		// }
		// If operand, add to postfix
        if(isalnum(ch)) {
            postfix += ch;
        }
		else if(ch=='(') st.push(ch);
		else if(ch==')'){
			while(st.top()!='('){
				char stEle = st.top();
				postfix+=stEle;
				st.pop();
			}
			if(!st.empty()) st.pop(); // Remove '('
		}
		// Operator: pop all with higher or equal precedence
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    // Pop remaining operators
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
	string exp = "(A/(B-C))*D+E";
	string ans = infixToPostFix(exp);
	cout<<"Postfix: "<<ans;
	return 0;
}