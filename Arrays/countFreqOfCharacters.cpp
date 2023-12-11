#include<bits/stdc++.h>
using namespace std;

string countEle(string str, int n){
	string ans="";
	int p1=0,p2=0;
	int count=0;
	while(p2<n){
		if(str[p1] == str[p2]){
			p2++;
			count++;
		}
		else if(str[p1]!=str[p2]){
			ans+=to_string(count)+str[p1];
			count=0;
			p1=p2;
		}
		else{
			p1++;
			p2++;
		}

	}
	ans+=to_string(count)+str[p1];
	return ans;
}

int main(){
	string str = "aaabbcccddddeeeef";
	 int n = str.length();

	 cout<<countEle(str,n);
	
	return 0;
}