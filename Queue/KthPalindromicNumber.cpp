#include <bits/stdc++.h>
using namespace std;

/* K = 10: 11,22,1(11)1*,[1(22)1]|2(11)2,2(22)2| 11(11)11*, 11(22)11*|
	[12(11)21], [12(22)21].....
*/
string KthPalindrome(string a, string b, int K){
	queue<string>q;
	q.push(a);
	q.push(b);
	int cnt = 2;
    if (K == 1) return a;
    if (K == 2) return b;
    while ((cnt) < K) {
        string s = q.front();
        q.pop();
        // Generate next palindromes by adding 1 and 2 at both ends
        string next1 = "1" + s + "1";
        string next2 = "2" + s + "2";
        q.push(next1);
        q.push(next2);
        cnt += 2;
    }

    // After loop, back of queue is Kth palindrome
    return q.back();
}

int main()
{	string a = "11", b="22";
	int K = 8;
	cout<<KthPalindrome(a,b,K);
	return 0;
}
