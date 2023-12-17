#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *left, *right;
		Node(int data){
			this->data = data;
			this->left = NULL;
			this->right=NULL;
		}
};
void printArray(vector<int> &arr){
	for(auto x:arr){
		cout<<x<<" ";
	}
	cout<<endl;
}

bool findNode(Node *root, int val, vector<int> &path){
	if(root==NULL) return false;
	if(root->data ==val) {
		path.push_back(root->data);
		return true;
	}
	bool search = findNode(root->left, val, path) || findNode(root->right, val, path);
	if(search){
		path.push_back(root->data);
		return true;
	}
	else{
		return false;
	}
}

int getLCS(Node *root,int data1, int data2){
	vector<int> path1;
	vector<int> path2;
	
	findNode(root,data1,path1);
	findNode(root,data2,path2);
	cout<<endl;
	cout<<"Path for 1st element: ";
	printArray(path1);

	cout<<"Path for 2nd element: ";
	printArray(path2);

	unordered_set<int>hs(path2.begin(), path2.end());
	for(auto x: path1){
		if(hs.find(x)!=hs.end()) return x;
	}
	return -1;
}

// GFG reference for Recursion solution
struct Node* findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL)
        return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->data == n1 || root->data == n2)
        return root;
 
    // Look for keys in left and right subtrees
    Node* left_lca = findLCA(root->left, n1, n2);
    Node* right_lca = findLCA(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one
    // key is present in once subtree and other is present
    // in other, So this node is the LCA
    if (left_lca && right_lca)
        return root;
 
    // Otherwise check if left subtree or right subtree is
    // LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}


Node *insertNode(Node *root, int data){
	if(root==NULL){
		Node * root = new Node(data);
		return root;
	}
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node *tmp = q.front();
		q.pop();
		if(tmp->left==NULL){
			tmp->left = new Node(data);
			return root;
		}
		if(tmp->right==NULL){
			tmp->right=new Node(data);
			return root;
		}
		if(tmp->left!=NULL){
			q.push(tmp->left);
		}
		if(tmp->right!=NULL){
			q.push(tmp->right);
		}
	}
	return NULL;
}

void inOrder(Node *root){
	if(root==NULL) return;
	inOrder(root->left);
	cout<<root->data<< " ";
	inOrder(root->right);
}

int main(){
	Node *root = new Node(10);
	root = insertNode(root,1);
	root = insertNode(root,2);
	root = insertNode(root,3);
	root = insertNode(root,7);
	root = insertNode(root,15);
	root = insertNode(root,5);
	root = insertNode(root,8);
	root = insertNode(root,12);
	root = insertNode(root,20);
	root = insertNode(root,13);
	root = insertNode(root,9);
	root = insertNode(root,6);
	inOrder(root);
	cout<<"Lowest Common Ancestor :"<<getLCS(root,13,8)<<endl;
	cout<<"Lowest Common Ancestor :"<<findLCA(root,13,8)->data;
	return 0;
}