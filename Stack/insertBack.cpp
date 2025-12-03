#include<bits/stdc++.h>
using namespace std;
/* Method 1: 
	- using another stack
	- push all elements in dummy stack
	- push X in original stack
	- push all element back to original stack from dummy stack
*/

//Method 2: Recursion
void insertBack(stack<int>&st, int x){
	if(st.size()==0) {
		st.push(x);
		return;
	}
	int ele = st.top();
	st.pop();
	insertBack(st,x);
	st.push(ele);
}

void printStack(stack<int>st){
	while(!st.empty()){
		int ele =st.top();
		cout<<ele<<" ";
		st.pop();
	}
}

int main(){
	stack<int> st;
	st.push(5);
	st.push(19);
	st.push(8);
	st.push(7);
	int x = 11;
	insertBack(st,x);
	printStack(st);
	return 0;
}