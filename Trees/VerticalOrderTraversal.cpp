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

void verticalOrderTraversal(TreeNode *root){
	unordered_map<int, vector<TreeNode *>> hm;
	queue<pair<TreeNode *,int>> q;
	q.push({root,0});

	int minLevel=0,maxLevel=0;
	while(!q.empty()){
		int currLevel = q.front().second;
		TreeNode *currNode = q.front().first;
		q.pop();
		vector<TreeNode*> currList = hm[currLevel];
		currList.push_back(currNode);
		hm[currLevel] = currList;
		minLevel = min(minLevel,currLevel);
		maxLevel = max(maxLevel,currLevel);
		if(currNode->left!=NULL){
			q.push({currNode->left,currLevel-1});
		}
		if(currNode->right!=NULL){
			q.push({currNode->right,currLevel+1});
		}
	}

	for(int i = minLevel;i<=maxLevel;i++){
		vector<TreeNode*> currList = hm[i];
		for(auto x: currList){
			cout<<x->data<<" ";
		}
	}

}
/*
				10

			7				15	

		4		6		12		20

	1
*/
int main(){
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(8);
	root->left->left = new TreeNode(4);
	root->left->left->right = new TreeNode(5);
	root->left->right = new TreeNode(9);
	root->left->left->left = new TreeNode(1);
	root->left->left->left->right = new TreeNode(3);
	root->right = new TreeNode(15);
	root->right->right = new TreeNode(20);
	root->right->right->left = new TreeNode(18);
	root->right->left = new TreeNode(12);
	cout<<"Inorder Traversal: ";
	inOrder(root);
	cout<<endl;
	cout<<"Vertical Order Traversal: ";
	verticalOrderTraversal(root);
	return 0;
}