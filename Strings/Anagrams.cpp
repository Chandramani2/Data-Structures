#include<bits/stdc++.h>
using namespace std;

bool areAnagrams(string &a, string &b){
	
	int n = a.length();
	int m = b.length();
	if(n!=m) return false;
	int CH[256] = {0};
	for(int i=0;i<n;i++){
		CH[a[i]-'a']++;
		CH[b[i]-'a']--;
	}
	for(int i=0;i<256;i++){
		if(CH[i]!=0) return false;
	}
	return true;
}

int main(){
	string a = "qwerty";
	string b = "wrtyqe";
	bool isAnagram = areAnagrams(a, b);
	if(isAnagram){
		cout<<"String: "<<a<<" and String: "<<b<<" are Anagrams";
	}
	else{
		cout<<"String: "<<a<<" and String: "<<b<<" are not Anagrams";
	}
	return 0;
}