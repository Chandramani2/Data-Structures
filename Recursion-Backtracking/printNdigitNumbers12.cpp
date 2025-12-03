#include<bits/stdc++.h>
using namespace std;
/* Print all N-digit number which can be formed by 1 and 2 */

void printVector(vector<int> arr){
	for(auto x: arr){
		cout<<x<<" ";
	}
	cout<<endl;
}
/*			1 1 1 
			1 1 2 
			1 2 1 
			1 2 2 
			2 1 1 
			2 1 2 
			2 2 1 
			2 2 2 
*/
// void printAll(int i, int N, vector<int> &ans){
// 	if(i==N){
// 		printVector(ans);
// 		return;
// 	}
// 	ans[i]=1;
// 	printAll(i+1,N,ans);
// 	ans[i] = 2;
// 	printAll(i+1,N,ans);
// }

void printAll(int i, int N, vector<int> ans){
	if(i==N){
		printVector(ans);
		return;
	}
	for(int j=0; j<10; j++){
		if(j==0 && i==0) continue;
		ans[i] = j;
		printAll(i+1,N,ans);
	}
}

void printNdigitNumber(int N){
	vector<int> ans(N);
	printAll(0,N,ans);
}

int main(){
	int N=3;
	printNdigitNumber(N);
	return 0;
}