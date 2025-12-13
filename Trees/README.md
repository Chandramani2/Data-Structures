# 🌲 Tree Data Structure Cheatsheet (C++)

A comprehensive guide to Binary Trees, Binary Search Trees (BST), traversals, and common algorithmic patterns used in interviews.

## 📖 Overview

A **Tree** is a hierarchical data structure.
* **Binary Tree:** Each node has at most 2 children.
* **BST:** Left < Node < Right.

### Node Structure
```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

---

## 🔍 Traversals

### 1. DFS (Recursive)
```cpp
void dfs(TreeNode* root) {
    if (!root) return;
    // Preorder: cout << root->val;
    dfs(root->left);
    // Inorder: cout << root->val;
    dfs(root->right);
    // Postorder: cout << root->val;
}
```

### 2. BFS (Level Order)
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q; q.push(root);
    
    while (!q.empty()) {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}
```

---

## 🌳 Binary Search Tree (BST)

### Search & Insert
```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
}
```

### Validate BST
```cpp
bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}
```

---

## 🧠 Common Patterns

### 1. Max Depth (Height)
```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

### 2. Lowest Common Ancestor (LCA)
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}
```

### 3. Diameter
Longest path between any two nodes.
```cpp
int maxD = 0;
int height(TreeNode* root) {
    if (!root) return 0;
    int l = height(root->left), r = height(root->right);
    maxD = max(maxD, l + r);
    return 1 + max(l, r);
}
```

### 4. Symmetric Tree (Mirror)
Check if the tree is a mirror of itself around the center.
```cpp
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2 || t1->val != t2->val) return false;
    // Compare outer pairs and inner pairs
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}
```

---

## ⚡ Complexity Cheatsheet

| Operation | General Tree | BST (Balanced) |
| :--- | :--- | :--- |
| **Search/Insert** | $O(N)$ | $O(\log N)$ |
| **Traversals** | $O(N)$ | $O(N)$ |
| **Space** | $O(H)$ | $O(H)$ |