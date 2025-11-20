#include<bits/stdc++.h>
using namespace std;
/* Given N return all N digit grey code Binary Number in decimal form
	Grey Code: B/w 2 consecutive number at max 1 bit can be different
		- Always start Grey code with 0
	N = 1, Grey code: 1, 0
	N = 2, Grey code: 00, 01, 11, 10 -> decimal: 0,1,3,2
		after 01 we wrote 11 not 10 becuz only 1 bit can be different
	N = 3, Grey code: 0|(00), 0|(01), 0|(11), 0|(10), 1|10, 1|11, 1|01, 1|00
		decimal values: 0,1,3,2,(2+4),(3+4),(1+4),(0+4) --- +4 because of 1 in front which is 2^2
	Observation:
		- All brackets Grey code is for N=2 and added 0&1 in front
		- grey codes after 1| is also grey code for N=2 but in Reverse order
	for N=4:
		ans = greyCode(N-3)
		greyCode(N) = (0+ans) + (1+reverse(ans))
*/

void printVector(vector<int> arr){
	for(auto x: arr){
		cout<<x<<" ";
	}
	cout<<endl;
}

vector<int> greyCode(int N){
	if(N==1) {
		vector<int>a = {0,1};
		return a;
	}	
	vector<int> a = greyCode(N-1);
	for(int i=a.size()-1; i>=0; i--){
		a.push_back(a[i] + (1<<(N-1)));
	}
	return a;
}

int main(){	
	int N=3;
	vector<int> gc = greyCode(N);
	printVector(gc);
	return 0;
}