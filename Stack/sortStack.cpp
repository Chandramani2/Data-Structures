#include<bits/stdc++.h>
using namespace std;

void printSortedStack(stack<int>stack1){
	while(!stack1.empty()){
		int temp = stack1.top();
		stack1.pop();
		cout<<temp<<" ";
	}
}

void sortStack(stack<int>&stack1, stack<int>&stack2){
	// In stack1 data should be sorted
 	// Move elements from stack1 to stack2 in sorted order
	while(!stack1.empty()){
		int temp = stack1.top();
		stack1.pop();
		// stack2 will be kept in descending order (largest at bottom, smallest at top)
		while(!stack2.empty() && temp<stack2.top()){
			int temp2 = stack2.top();
			stack1.push(temp2);
			stack2.pop();	
		}
		stack2.push(temp);
	}

	cout<<"Printing From Stack 2: Descending order\n";
	printSortedStack(stack2);

  // Now move back to stack1 so that stack1 is sorted ascending (smallest at bottom, largest at top)
    while (!stack2.empty()) {
        int temp2 = stack2.top();
		stack1.push(temp2);
		stack2.pop();	
    }
}


int main(){
	stack<int>st;
	st.push(4);
	st.push(6);
	st.push(-5);
	st.push(0);
	st.push(-1);
	st.push(2);
	st.push(5);
	st.push(3);
	st.push(1);

	stack<int> st2;
	sortStack(st, st2);
	cout<<"\n\nPrinting From Stack 1: Ascending Order\n";
	printSortedStack(st);
	return 0;
}