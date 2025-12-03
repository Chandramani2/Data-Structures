#include<bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
	int data;
	TreeNode *left, *right;
	TreeNode(int data){
		this->data = data;
		left=right=NULL;
	}
};

//Invert BT
void invertBT(TreeNode *root){
	if(root==NULL) return;
	invertBT(root->left);
	invertBT(root->right);
	//swap node
	TreeNode *tmp = root->right;
	root->right = root->left;
	root->left = tmp;
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
	invertBT(root);
	cout<<"\nAfter Invert Inorder: ";
	inOrder(root);
	return 0;
}