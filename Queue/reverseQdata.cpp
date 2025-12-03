#include<bits/stdc++.h>
using namespace std;
/* Given Q data, reverse the data using stack*/

void printQData(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

void reverseQData(queue<int>&q, stack<int>st){
	printQData(q);
	while(!q.empty()){
		st.push(q.front());
		q.pop();
	}
	while(!st.empty()){
		q.push(st.top());
		st.pop();
	}
	printQData(q);
}


int main()
{
	queue<int>q;
	stack<int>st;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	reverseQData(q,st);
	return 0;
}
