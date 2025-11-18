#include<bits/stdc++.h>
using namespace std;
/* Re-arrange Array to make sequence consecutive and return the longest one
	In this example {6,7,10,8,14,9,12,13,15}
	sequence 1: 6,7,8,9,10
	sequence 2: 12,13,14,15
	sequence 3: any smaller sequence will already there be sequence 1&2
	so sequence 1 is longest
*/
void printVectors(vector<int> arr){
	for(auto x: arr){
		cout<<x<<" ";
	}
	cout<<endl;
}

// Sort and check adjacent elements
int longestConsecutiveSequenceNaive(vector<int> arr){
	sort(arr.begin(), arr.end());
	int ans = 0;
	int currentSequence = 1;
	for(int i=1; i<arr.size(); i++){
		if(arr[i] == arr[i-1]+1){
			currentSequence++;
		}
		else currentSequence = 0;
		ans = max(ans, currentSequence);
	}
	return ans;
}

/* Assume every element as starting of the sequence and 
start looking for the next element in the remaining array
*/
int longestConsecutiveSequenceOptimized(vector<int> arr){
	unordered_set<int> hs;
	//Insert all elements in Hashset
	for(auto x: arr) hs.insert(x);

	/* before starting sequence check prev val of the
	current element, if prev val is present
	we don't need to start the sequence from ther current element
	*/
	int ans = 0;
	for(auto x: arr){
		if(hs.find(x-1)!=hs.end()) continue; //we don't start the sequence 
		for(int i=1; i<arr.size(); i++){
			if(hs.find(x+i)!=hs.end()){
				ans = max(ans, i+1);
			}
			else break;
		}
	}
	return ans;
}
int main(){
	vector<int>arr = {9,-1,-3,7,0,6,-2,11,12,14,15,1,6,8};
	cout<<"longest Sequence of consecutive elements Naive: "
	<<longestConsecutiveSequenceNaive(arr)<<endl;
	cout<<"longest Sequence of consecutive elements Optimized: "
	<<longestConsecutiveSequenceOptimized(arr);
	return 0;
}