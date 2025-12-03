#include <bits/stdc++.h>
using namespace std;

/* K = 10: 1,2,11,12,21,22,111,112,121,122,211: 
	Ans: 122 -> 10th in the series
*/
string KthSmallestElement(string a, string b, int K){
	queue<string>q;
	q.push(a);
	q.push(b);
	int deleted = 0;
	while(q.size()+deleted != K){
		string f = q.front();
		q.pop();
		deleted++;
		q.push(f+'1');
		q.push(f+'2');
	}
	return q.back();
}

int main()
{	string a = "1", b="2";
	int K = 10;
	cout<<KthSmallestElement(a,b,K);
	return 0;
}
