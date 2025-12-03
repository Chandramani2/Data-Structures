#include<bits/stdc++.h>
using namespace std;
/* Given source Node, get Number of Nodes at distance K
	below that source Node (Successor)
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

void printNodes(vector<TreeNode*>arr){
	for(auto x:arr){
		cout<<x->data<<" ";
	}
	cout<<endl;
}

// Nodes Below source Node at distance K
int nodeBelowK(TreeNode *source, int K, vector<int> &ans){
	if(source==NULL) return 0;
	if(K==0) {
		ans.push_back(source->data);
		return 1;
	}
	int cntLeft = nodeBelowK(source->left, K-1, ans);
	int cntRight = nodeBelowK(source->right, K-1, ans);
	return cntLeft + cntRight;
}

/* Q.2: get No. of Nodes at Distance K from given source Node
	- There can be Nodes above source Node as well at Distance K
	- No Successor any Nodes at Distance K from the source Node
*/
bool pathFromRootNode(TreeNode *root, TreeNode *source, vector<TreeNode*> &path ){
	if(root==NULL) return false;
	if(root==source) {
		path.push_back(root);
		return true;
	}
	bool searchL = pathFromRootNode(root->left,source,path);
	bool searchR = pathFromRootNode(root->right,source,path);
	if(searchL || searchR){
		path.push_back(root);
		return true;
	}
	return false;

}
int nodesAtDistanceK(TreeNode *root, TreeNode *source, int K, vector<int>&ans){
	vector<TreeNode*> path;
	pathFromRootNode(root, source, path);
	cout<<"\npath of source node from root node: ";
	printNodes(path);
	/*Iterate on the path and select source node with distance K-1
		and run nodeBelowK function to calculate 
	*/
	int cnt = 0;
	cnt = nodeBelowK(source,K,ans);
	K--;
	for(int i=1; i < path.size(); i++){
			// if(K==0) ans.push_back(path[i]->data); // edge case
			if(K <= 0) {
				ans.push_back(path[i]->data);
				break;
			}
			if(path[i]->left == path[i-1])	
				cnt+=nodeBelowK(path[i]->right, K-1, ans);
			else if(path[i]->right == path[i-1])
				cnt+=nodeBelowK(path[i]->left, K-1, ans);
			K--;
	}
	return cnt;
}
void inOrder(TreeNode *root){
	if(root==NULL) return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
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

	1      7		  15			32

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
	root->right->right->right = new TreeNode(32);
	root->right->left = new TreeNode(20);
	root->right->left->left = new TreeNode(15);
	root->right->left->left->left = new TreeNode(14);
	root->right->left->left->left->left = new TreeNode(12);
	cout<<"Inorder Traversal BST sorted: ";
	inOrder(root);

	int K = 1;
	vector<int>ans; // store all nodes at distance K
	cout<<"\nNumber of Nodes below " + 
	to_string(root->right->data) + ": "
	<<nodeBelowK(root->right, K, ans); 
	// 20 & 30 at K = 1, ans=2
	cout<<"\nNodes Below at Distance "+to_string(K)+" from "+
	to_string(root->right->data) + ": ";
	printArray(ans);

	//Q.2: Nodes At Distance K in any direction from the source node
	K = 2;
	ans.clear();
	nodesAtDistanceK(root, root->right->left, K, ans); 
	cout<<"\nNumber of Nodes at Distance "+to_string(K)+" from "+
	to_string(root->right->left->data) + ": "
	<<ans.size();
	
	cout<<"\nNodes at Distance "+to_string(K)+" from "+
	to_string(root->right->left->data) + ": ";
	printArray(ans);
	return 0;
}