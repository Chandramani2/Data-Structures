#include "bits/stdc++.h"
using namespace std;

struct Node{
	Node *ch[2];
	int cnt;
	bool isEnd;
	Node(){
		isEnd = false;
		cnt=0;
		for(int i=0; i<2; i++) ch[i] = nullptr;
	}
};

class Trie{
public:
	Node *root;
	Trie(){
		root = new Node();
	}

	void insert(vector<int> binaryList){
		Node *current = root;
		for(int binary: binaryList){
			if(current->ch[binary] == nullptr){
				current->ch[binary] = new Node();
			}
			current = current->ch[binary];
			current->cnt++;
		}
		current->isEnd = true;
	}
	void searchPrefix(Node *current, string prefix, string &result){
			if(current == nullptr) return;

			if(current->isEnd) result += prefix + ":" + to_string(current->cnt) + ", ";
			for(int i=0; i<2; i++){
				if(current->ch[i] !=nullptr)
					searchPrefix(current->ch[i], prefix + to_string(i), result);
			}

		}

	string searchAllPrefix(string prefix){
		Node *current = root;
		
		for(char preCh: prefix){
			int bit = preCh - '0'; // Convert char '0'/'1' to int 0/1
			if(bit < 0 || bit > 1 || current->ch[bit]==nullptr) return "";
			current = current->ch[bit];
		}
		string result = "";
		searchPrefix(current, prefix, result);
		if(result.empty()) return "";
		// Remove the trailing comma and space
		result.erase(result.length()-2); // ", "
		return result;	
	}
};
int main(int argc, char const *argv[])
{	
	vector<vector<int>> mat = { {1,0,1,0,1,0,0,1,1},
								{1,1,1,0,1,0,1,1,1},
								{1,0,1,0,1,0,0,1,1},
								{1,0,1,1,1,0,0,1,1},
								{1,0,1,0,1,1,0,1,1},
								{1,0,1,0,1,0,0,1,1}};
	Trie trie;
    for (const auto& row : mat) {
        trie.insert(row);
    }

    // Search for all sequences starting with "10"
    string matches = trie.searchAllPrefix("101");
    cout << "Matches found:\n" << matches << endl;
	return 0;
}
