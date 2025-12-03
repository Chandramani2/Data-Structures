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

void inOrder(TreeNode *root){
	if(root==NULL) return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void levelOrderTraversal(TreeNode *root){
	queue<TreeNode *> q;
	q.push(root);
	while(!q.empty()){
		TreeNode *node = q.front();
		q.pop();
		cout<<node->data<<" ";
		if(node->left!=NULL){
			q.push(node->left);
		}
		if(node->right!=NULL){
			q.push(node->right);
		}
	}
}

void levelOrderTraversalLineByLine(TreeNode *root){
	queue<TreeNode *> q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		while(n>0){
			TreeNode *node = q.front();
			q.pop();
			cout<<node->data<<" ";
			if(node->left!=NULL){
				q.push(node->left);
			}
			if(node->right!=NULL){
				q.push(node->right);
			}
			n--;
		}
		cout<<" NULL "<<endl;		
	}
}

vector<vector<int>> levelOrderReverseAlternateTraversal(TreeNode *root){
	queue<TreeNode *> q;
	q.push(root);
	int cnt = 0;
	vector<vector<int>> ans;
	while(!q.empty()){
		int n = q.size();
		vector<int> tmp;
		while(n>0){
			TreeNode *node = q.front();
			q.pop();
			tmp.push_back(node->data);
			if(node->left!=NULL){
				q.push(node->left);
			}
			if(node->right!=NULL){
				q.push(node->right);
			}
			n--;
		}
		cnt++;
		if(cnt%2==0) reverse(tmp.begin(),tmp.end());
		ans.push_back(tmp);		
	}
	return ans;
}
void print2DArray(vector<vector<int>> & arr){
	int n = arr.size();
	for(int i=0;i<n;i++){
		for(auto x: arr[i]){
			cout<<x<<" ";
		}
		cout<<" NULL "<<endl;
	}
}
/*
					10

			8				15	

		4		9		12		20

	1       7          30
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
	cout<<"Inorder Traversal: ";
	inOrder(root);
	cout<<endl;
	cout<<endl;
	cout<<"Level Order Traversal: ";
	levelOrderTraversal(root);
	cout<<endl;
	cout<<endl;
	cout<<"Level Order Traversal Line By Line: "<<endl;
	levelOrderTraversalLineByLine(root);
	cout<<endl;
	cout<<"Level Order Alternate Reversal Traversal Line By Line: "<<endl;
	vector<vector<int>> ans = levelOrderReverseAlternateTraversal(root);
	print2DArray(ans);
	return 0;
}