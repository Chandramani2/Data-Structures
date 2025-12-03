#include "bits/stdc++.h"
using namespace std;
/* Elements are Distinct */
class TreeNode{
	public:
		int data;
		TreeNode *left, *right;
		TreeNode(int data){
			this->data = data;
			left=right=NULL;
		}										
};

void printArray(vector<int> &arr){
	for(auto x:arr){
		cout<<x<<" ";
	}
	cout<<endl;
}

//count number of Leaf Nodes
int leafNodes(TreeNode *root){
	if(root==NULL) return 0;
	if(root->left==NULL && root->right==NULL) return 1;
	return leafNodes(root->left) + leafNodes(root->right);
}

// apply any traversal and check if K present
bool Search(TreeNode *root, int K){
	if(root==NULL) return false;
	if(root->data==K) return true;
	return Search(root->left, K) || Search(root->right, K);
}

// get path of the Node K from the root Node
bool findNode(TreeNode *root, int val, vector<int> &path){
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

void inOrder(TreeNode *root){
	if(root==NULL) return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
/*
					10

			8				15	

		4		9		12		20

	1      7		  30

					14

				40
*/
int main(){
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(8);
	root->left->left = new TreeNode(4);
	root->left->left->right = new TreeNode(7);
	root->left->right = new TreeNode(9);
	root->left->left->left = new TreeNode(1);
	root->right = new TreeNode(15);
	root->right->right = new TreeNode(20);
	root->right->left = new TreeNode(12);
	root->right->left->left = new TreeNode(30);
	root->right->left->left->left = new TreeNode(14);
	root->right->left->left->left->left = new TreeNode(40);
	cout<<"Inorder Traversal: ";
	inOrder(root);
	cout<<endl;
	cout<<"Leaf Nodes: "<<leafNodes(root);
	// verticalOrderTraversal(root);
	int K = 30;
	cout<<"\nSearch: "<<Search(root, K);
	vector<int>path;
	cout<<"\nSearch: "<<findNode(root, K, path);
	cout<<"\nPath: ";
	printArray(path);
	return 0;
}
