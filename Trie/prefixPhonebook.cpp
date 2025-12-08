#include <bits/stdc++.h>
using namespace std;

struct Node{
	bool isEndOfWord;
	int phone;
	unordered_map<char, Node*> children;
	Node(){
		isEndOfWord = false;
	}
};

class Trie{
	public:
		Node *root;
		Trie(){
			root = new Node();
		}
		void insert(string word, int phone){
			Node * current = root;
			for(char ch: word){
				if(!(current -> children.count(ch))){
					current->children[ch] = new Node();
				}
				current = current->children[ch];
			}
			current->isEndOfWord = true;
			current->phone = phone;
		}
		bool search(string word){
			Node *current = root;
			for(char ch: word){
				if(!(current -> children.count(ch))){
					return false;
				}
				current = current->children[ch];
			}
			return current->isEndOfWord;
		}
		void searchPrefix(Node *current, string prefix, string &result){
			if(current == NULL) return;

			if(current->isEndOfWord){
				result += prefix + ":" + to_string(current->phone) + ", ";
			}

			for(auto&pair: current->children){
				searchPrefix(pair.second, prefix + pair.first, result);
			}
		}

		string searchAllPrefix(string prefix){
			Node *current = root;
			string result = "";
			for(char ch: prefix){
				if(!(current -> children.count(ch))){	
					return "";
				}
				current = current->children[ch];
			}
			searchPrefix(current, prefix, result);
			if(result.empty()) return "";
			else{
				result.pop_back();
				return result;
			}
	}
};
int main() {
	Trie trie;
	trie.insert("Anuj",898798797);
	trie.insert("Swiggy",623746);
	trie.insert("Zomato",78346857);
	trie.insert("Anudygu",67125347);
	trie.insert("iuehi",92834798);
	trie.insert("iueewtwe",2374892);

	string matches = trie.searchAllPrefix("iu");
	cout<<"All Prefix String: \n"<< matches;

   return 0;
}
