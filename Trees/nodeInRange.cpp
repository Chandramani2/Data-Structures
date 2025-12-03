#include<bits/stdc++.h>
using namespace std;
/* Problem: Return BST with all the data in Range [L,R]
	- remove data which is not in range
*/
class TreeNode{
	public:
	int data;
	TreeNode *left, *right;
	TreeNode(int data){
		this->data = data;
		left=right=NULL;
	}
};
/* Method 1: Do Preorder, If node within the range them
	Insert that data in new BST
*/
// Insertion Iterative
TreeNode *insertNodeK(TreeNode *root, int K) {
    TreeNode *newNode = new TreeNode(K);
    if (root == NULL) return newNode;

    TreeNode *curr = root;
    while (true) {
        if (curr->data > K) { // goto left side
            if (curr->left == NULL) {
                curr->left = newNode;
                break;
            } else {
                curr = curr->left;
            }
        } else if (curr->data < K) { // goto right side
            if (curr->right == NULL) {
                curr->right = newNode;
                break;
            } else {
                curr = curr->right;
            }
        } else {
            // Duplicate found, delete newNode and return original root
            delete newNode;
            return root;
        }
    }
    return root;
}

// Insertion Recursive
TreeNode *insert(TreeNode *root, int val){
	if(root==NULL) return new TreeNode(val);
	if(val < root->data)
		root->left = insert(root->left, val);
	else if(val > root->data)
		root->right = insert(root->right, val);
	return root;
}

void preOrder(TreeNode *root, TreeNode *&newRoot, int L, int R){
	if(root==NULL) return;
	if(root->data>=L && root->data<=R){
		newRoot = insert(newRoot, root->data);
	}
	preOrder(root->left, newRoot, L, R);
	preOrder(root->right, newRoot, L, R);
}

/* Method 2: Recursion */
TreeNode *BSTInRange(TreeNode *root, int L, int R){
 	if(root == NULL) return NULL;

    // If current node is outside the range, ignore it and process its children
    if(root->data < L) return BSTInRange(root->right, L, R);
    if(root->data > R) return BSTInRange(root->left, L, R);

    // If node is in range, include it and recursively process both children
    root->left = BSTInRange(root->left, L, R);
    root->right = BSTInRange(root->right, L, R);
    return root;
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
	int L = 6, R = 22;
	TreeNode *newRoot = NULL;

	preOrder(root, newRoot, L, R);
	cout<<"\nInorder [L,R]: ";
	inOrder(newRoot);
	
	BSTInRange(root, L, R);
	cout<<"\nInorder [L,R]: ";
	inOrder(newRoot);
	return 0;
}