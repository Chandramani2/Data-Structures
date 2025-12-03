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

// floor(K) in BST
int floorBST(TreeNode *root, int K){
	int ans = INT_MIN;
	while(root!=NULL){
		if(root->data == K) return K;
		else if(root->data < K){
			ans = root->data;
			// look for better answer on right side
			root = root->right; 
		}
		else{
			root = root->left;
		}
	}
	return ans;
}

// ceil(K) in BST
int ceilBST(TreeNode *root, int K){
	int ans = INT_MIN;
	while(root!=NULL){
		if(root->data == K) return K;
		else if(root->data > K){
			ans = root->data;
			// look for better answer on left side
			root = root->left; 
		}
		else{
			root = root->right;
		}
	}
	return ans;
}

void inOrder(TreeNode *root){
	if(root==NULL) return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

/*
					10

			8				25	

		4		9		20		30

	1      7		  15

					14

				12
*/
int main(){
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(8);
	root->left->left = new TreeNode(4);
	root->left->left->right = new TreeNode(7);
	root->left->right = new TreeNode(9);
	root->left->left->left = new TreeNode(1);
	root->right = new TreeNode(25);
	root->right->right = new TreeNode(30);
	root->right->left = new TreeNode(20);
	root->right->left->left = new TreeNode(15);
	root->right->left->left->left = new TreeNode(14);
	root->right->left->left->left->left = new TreeNode(12);
	cout<<"Inorder Traversal BST sorted: ";
	inOrder(root);
	
	int K = 17;
	cout<<"\nFloor: "<<floorBST(root, K);
	cout<<"\nCeil: "<<ceilBST(root, K);

	return 0;
}