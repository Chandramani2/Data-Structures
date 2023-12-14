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

int HeightBinaryTree(Node *root){
	if(root==NULL) return 0;
	int l = HeightBinaryTree(root->left);
	int r = HeightBinaryTree(root->right);
	return max(l,r) +1;
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
	// root->left = new Node(7);
	// root->left->left = new Node(5);
	// root->left->right = new Node(8);
	// root->right = new Node(15);
	// root->right->left = new Node(12);
	// root->right->right = new Node(20);
	root = insertNode(root,7);
	root = insertNode(root,15);
	root = insertNode(root,5);
	root = insertNode(root,8);
	root = insertNode(root,12);
	root = insertNode(root,20);
	inOrder(root);
	cout<<endl;
	cout<<"Height Of Binary Tree: " <<HeightBinaryTree(root);
	return 0;
}