# ▦ Matrix Cheatsheet (C++)

A comprehensive guide to 2D Arrays (Matrices), covering storage, traversal patterns, standard algorithms (Rotation, Spiral), and Grid Search techniques.

## 📖 Overview

A **Matrix** is a collection of numbers arranged in rows and columns. In C++, it is typically represented as a `vector<vector<int>>`.

### Standard Representation
```cpp
// R rows, C columns
int R = 3, C = 4;
vector<vector<int>> matrix(R, vector<int>(C, 0));
```

---

## 🛠 Standard Traversals

### 1. Row-Major (Standard)
Best for caching performance.
```cpp
for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
        cout << matrix[i][j] << " ";
    }
}
```

---

## 🧠 Essential Algorithms

### 1. Transpose Matrix
Swap rows and columns.
```cpp
void transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
```

### 2. Rotate Image (90° Clockwise)
**Step 1:** Transpose. **Step 2:** Reverse Rows.
```cpp
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) swap(matrix[i][j], matrix[j][i]);
    
    // Reverse Rows
    for (int i = 0; i < n; i++) reverse(matrix[i].begin(), matrix[i].end());
}
```

### 3. Spiral Traversal
Traverse boundaries: Top→Right→Bottom→Left.
```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) res.push_back(matrix[top][i]); top++;
        for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]); right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]); bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]); left++;
        }
    }
    return res;
}
```

### 4. Search in Sorted 2D Matrix
Rows sorted L-R, Cols sorted T-B. Start **Top-Right**.
```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = 0, c = matrix[0].size() - 1;
    while (r < matrix.size() && c >= 0) {
        if (matrix[r][c] == target) return true;
        else if (matrix[r][c] > target) c--; // Go Left
        else r++; // Go Down
    }
    return false;
}
```

---

## compass Grid Navigation (BFS/DFS Helper)
Using delta arrays for cleaner code.

```cpp
int dr[] = {0, 1, 0, -1}; // Right, Down, Left, Up
int dc[] = {1, 0, -1, 0};

// Inside Loop
int nr = r + dr[i];
int nc = c + dc[i];
if (isValid(nr, nc)) { ... }
```

---

## ⚡ Complexity Cheatsheet

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Access/Traversal** | $O(R \times C)$ | $O(1)$ |
| **Transpose/Rotate** | $O(R \times C)$ | $O(1)$ |
| **Search (Sorted)** | $O(R + C)$ | $O(1)$ |