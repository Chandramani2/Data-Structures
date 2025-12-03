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

// Method 1: Inorder Traversal store in array and check sorted or not
void inOrder(TreeNode *root, vector<int> &inorderArr){
	if(root==NULL) return;
	inOrder(root->left, inorderArr);
	inorderArr.push_back(root->data);
	inOrder(root->right, inorderArr);
}

// TC:O(N), SC:O(N)
bool checkSorted(vector<int>arr){
	for(int i =0; i<arr.size()-1; i++){
		if(arr[i]>arr[i+1]) return false;
	}
	return true;
}

/* Method 2: Inorder Traversal compare prev node data
		(should be smaller becasue inorder sorted) 
		with current one
*/
bool inOrderPrevData(TreeNode *root, int &prev) {
    if (root == NULL) return true;
    if (!inOrderPrevData(root->left, prev)) return false;
    if (prev >= root->data) return false; // BST doesn't allow duplicates
    prev = root->data;
    return inOrderPrevData(root->right, prev);
}

// Method 3: check range for every node
bool checkBST(TreeNode *root, int minVal, int maxVal) {
    if (root == NULL) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return checkBST(root->left, minVal, root->data) &&
           checkBST(root->right, root->data, maxVal);
}

void printArray(vector<int>arr){
	for(auto x:arr){
		cout<<x<<" ";
	}
	cout<<endl;
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

	vector<int>inorderArr;
	cout<<"Inorder Traversal BST sorted: ";
	inOrder(root, inorderArr);
	printArray(inorderArr);
	
	cout<<"checkBST1: "<<checkSorted(inorderArr);
	int prev = INT_MIN;
	cout<<"\ncheckBST2: "<<inOrderPrevData(root, prev);
	int L = INT_MIN;
	int R = INT_MAX;
	cout<<"\ncheckBST3: "<<checkBST(root, L, R);

	return 0;
}