# 🌳 Trie (Prefix Tree) Cheatsheet (C++)

A comprehensive guide to the **Trie** data structure, used for efficient string retrieval, prefix matching, and autocomplete systems.

## 📖 Overview

A **Trie** is a tree where edges represent characters.
* **Root:** Empty.
* **Children:** Array of size 26 (for 'a'-'z').

### Node Structure
```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};
```

---

## 🛠 Standard Operations

### 1. Insert (O(L))
```cpp
void insert(TrieNode* root, string word) {
    TrieNode* curr = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!curr->children[idx]) curr->children[idx] = new TrieNode();
        curr = curr->children[idx];
    }
    curr->isEnd = true;
}
```

### 2. Search (O(L))
Returns true only if the word exists completely.
```cpp
bool search(TrieNode* root, string word) {
    TrieNode* curr = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!curr->children[idx]) return false;
        curr = curr->children[idx];
    }
    return curr->isEnd;
}
```

### 3. StartsWith (O(L))
Returns true if any word in the Trie starts with this prefix.
```cpp
bool startsWith(TrieNode* root, string prefix) {
    TrieNode* curr = root;
    for (char c : prefix) {
        int idx = c - 'a';
        if (!curr->children[idx]) return false;
        curr = curr->children[idx];
    }
    return true;
}
```

---

## 🧠 Essential Applications

### 1. Autocomplete (DFS)
Traverse to the end of the prefix, then DFS to find all complete words.

```cpp
void dfs(TrieNode* curr, string path, vector<string>& res) {
    if (curr->isEnd) res.push_back(path);
    for (int i = 0; i < 26; i++) {
        if (curr->children[i]) {
            path += char('a' + i);
            dfs(curr->children[i], path, res);
            path.pop_back();
        }
    }
}
```

### 2. Maximum XOR (Binary Trie)
Insert numbers as 32-bit binary paths. To maximize XOR, try to traverse the **opposite** bit (0->1, 1->0) at each step.

```cpp
struct BitNode { BitNode* child[2]; }; // 0 and 1

// Walk down trying to go opposite
int getMaxXor(BitNode* root, int num) {
    BitNode* curr = root;
    int maxXor = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (curr->child[1 - bit]) {
            maxXor |= (1 << i);
            curr = curr->child[1 - bit];
        } else {
            curr = curr->child[bit];
        }
    }
    return maxXor;
}
```

---

## ⚡ Complexity Cheatsheet

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Insert** | $O(L)$ | $O(L \times 26)$ |
| **Search** | $O(L)$ | $O(1)$ |
| **Space** | - | High (Sparse Nodes) |