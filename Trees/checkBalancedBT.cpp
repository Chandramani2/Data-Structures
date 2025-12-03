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
// Height of BT
int HeightBT(TreeNode *root){
	if(root==NULL) return 0;
	return max(HeightBT(root->left), HeightBT(root->right))+1;
}

// TC: O(N^2)
bool balanced(TreeNode *root){
	if(root==NULL) return true;
	bool l = balanced(root->left);
	bool r = balanced(root->right);
	// calculating height for every node is taking time
	int lh = HeightBT(root->left);
	int rh = HeightBT(root->right);
	if ((l && r) && abs(lh-rh)<=1) return true;
	else return false;
}
// check balanced while calculating height
int heightBalanced(TreeNode *root, bool &ans){
	if(root==NULL) return 0;
	int l = heightBalanced(root->left, ans);
	int r = heightBalanced(root->right, ans);
	if(abs(l-r) > 1) ans = false;
	return max(l,r) + 1;
}

/* store height */
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
	// root->right->left->left->left = new TreeNode(14);
	// root->right->left->left->left->left = new TreeNode(40);
	cout<<"Inorder Traversal: ";
	inOrder(root);
	cout<<"\nBalanced: "<<balanced(root);
	bool ans = true;
	cout<<"\nHeight Balanced: "<<ans<<" , Height: "<<heightBalanced(root, ans);

	return 0;
}