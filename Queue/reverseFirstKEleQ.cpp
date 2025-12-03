#include<bits/stdc++.h>
using namespace std;
/* Given Q data, reverse the first K element data using stack*/

void printQData(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

void reverseFirstKQData(queue<int>&q, stack<int>st, int K){
	printQData(q);
	int remainingEle = q.size()-K;

	while(K>0 && !q.empty()){
		st.push(q.front());
		q.pop();
		K--;
	}
	while(!st.empty()){
		q.push(st.top());
		st.pop();
	}

	while(remainingEle>0){
		q.push(q.front());
		q.pop();
		remainingEle--;
	}
	printQData(q);
}


int main()
{
	queue<int>q;
	stack<int>st;
	int K = 4;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);

	reverseFirstKQData(q,st,K);
	return 0;
}
