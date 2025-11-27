#include<bits/stdc++.h>
using namespace std;
/* How many ways we can partition a given string using 
    given set of string
*/

int waysPartition(string s, int i, set<string> words){
    if(i==s.size()) return 1;
    int count = 0;
    string c;
    for(int j=i;j<s.size(); j++){
        c = c+s[j];
        if(words.find(c)!=words.end()){
            count+=waysPartition(s,j+1,words);
        }
    }
    return count;
}

int main(){
    string s = "Interviewbit";
    set<string> words = {"Int", "Bit", "view", "Interview", "In", "ter",
                    "bi", "t", "er", "erview"};
    int i=0;
    cout<<"Number of ways for string: " + s + ": "<<waysPartition(s, i, words);
    return 0;
}