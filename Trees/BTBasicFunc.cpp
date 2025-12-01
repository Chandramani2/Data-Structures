#include "bits/stdc++.h"
using namespace std;

class Node{
	public:
		int data;
		Node *left, *right;
		Node(int data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
};
// Inorder Traversal
void inOrder(Node *root){
	if(root==NULL) return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

// preorder Traversal
void preOrder(Node *root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

//postorder Traversal
void postOrder(Node *root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

// size of the BT -> No. of Nodes
int size(Node *root){
	if(root==NULL) return 0;
	return size(root->left)+size(root->right)+1;
}

//sum of all Nodes
int sum(Node *root){
	if(root==NULL) return 0;
	return sum(root->left)+sum(root->right)+root->data;
}

//max of all Nodes
int maxNode(Node *root){
	// if all Node is -ve, we cannot return 0.
	if(root==NULL) return INT_MIN;
	return max(root->data,max(maxNode(root->left), maxNode(root->right)));
}

// Height
int HeightBinaryTree(Node *root){
	if(root==NULL) return 0;
	int l = HeightBinaryTree(root->left);
	int r = HeightBinaryTree(root->right);
	return max(l,r) +1;
}

// Max path across the root Node
int maxPathAcrossRootNode(Node *root){
	if(root==NULL) return 0;
	return HeightBinaryTree(root->left) + HeightBinaryTree(root->right) + 2;
}

/*Max path in whole BT, Height & maxPathAcrossRootNode 
	code with some modification..
	- Diameter of the BT
*/
int maxPathBT(Node *root, int &ans){
	if(root==NULL) return 0;
	int l = maxPathBT(root->left,ans);
	int r = maxPathBT(root->right,ans);
	ans = max(ans, l+r+2); // this will be the output
	return max(l,r)+1;
}

int main()
{	Node *root = new Node(10);
	root->left = new Node(7);
	root->left->left = new Node(5);
	root->left->right = new Node(8);
	root->right = new Node(15);
	root->right->left = new Node(12);
	root->right->right = new Node(20);
	cout<<"Inorder: ";
	inOrder(root);
	cout<<endl<<"Preorder: ";
	preOrder(root);
	cout<<endl<<"Postorder: ";
	postOrder(root);
	cout<<endl<<"Size: "<<size(root);
	cout<<endl<<"Sum: "<<sum(root);
	cout<<endl<<"Max Value Node: "<<maxNode(root);
	cout<<endl<<"Height: "<<HeightBinaryTree(root);
	cout<<endl<<"Max Path Across Root Node: "<<maxPathAcrossRootNode(root);
	int ans = 0;
	maxPathBT(root, ans);
	cout<<endl<<"Max Path in whole BT: "<< ans;
	return 0;
}
