#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(string str, int n, vector<int> &lps){
	int x = 0;
	for(int i=1;i<n;i++){
		x = lps[i-1];
		while(x>0 && str[x]!=str[i]){
			x = lps[x-1];
		}
		if(str[x]==str[i]){
			lps[i] = x+1;
		}
	}
}
void printArray(vector<int> &arr){
	for(auto x:arr) cout<< x << " ";
		cout<<endl;
}
int main(){
	string str = "cacxcacabcacxcacx";
	int n = str.length();
	vector<int>lps(n,0);
	computeLPSArray(str,n,lps);
	printArray(lps);
	return 0;

}


