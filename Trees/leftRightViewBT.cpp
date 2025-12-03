#include "bits/stdc++.h"	
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

void printLeftView(TreeNode *root){
	queue<TreeNode*> q;
	q.push(root);
	cout<<root->data<<" ";
	while(!q.empty()){
		int n = q.size();
		bool newLevel = true;
		while(n>0){
			TreeNode *tmp = q.front();
			q.pop();
			if(tmp->left!=NULL){
				q.push(tmp->left);
				if(newLevel){
					cout<<tmp->left->data<<" ";
					newLevel = false;
				}
			}
			if(tmp->right!=NULL){
				q.push(tmp->right);
			}
			n--;
		}	
	}
}

void printRightView(TreeNode *root){
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		TreeNode *last;
		while(n>0){
			TreeNode *tmp = q.front();
			q.pop();
			last=tmp;
			if(tmp->left!=NULL){
				q.push(tmp->left);
			}
			if(tmp->right!=NULL){
				q.push(tmp->right);
			}
			n--;
		}	
		cout<<last->data<<" ";
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
	cout<<"\nLeft View: ";
	printLeftView(root);
	cout<<"\nRight View: ";
	printRightView(root);
	return 0;
}											