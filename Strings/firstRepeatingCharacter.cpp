#include<bits/stdc++.h>
using namespace std;

char firstRepeatingCharacter(string &a){
	
	int n = a.length();
	int CH[256]={0};
	for(int i=0;i<n;i++){
		char ans = a[i]-'a';
		CH[ans]++;
		if(CH[ans]>1) return ans+'a';
	}
	return '@';
	
}
char firstCharacter(string &a){
	
	int n = a.length();
	int CH[256]={0};
	for(int i=0;i<n;i++){
		char ans = a[i]-'a';
		CH[ans]++;
	}
	for(int i=0;i<n;i++){
		char ans = a[i]-'a';
		if(CH[ans]>1) return ans+'a';
	}
	return '@';
	
}

int main(){
	string a = "qwertyerwt";
	cout<<"First Repeating Character is: "<<firstRepeatingCharacter(a)<<endl;
	cout<<"First Character Occured is: "<<firstCharacter(a);
	return 0;
}