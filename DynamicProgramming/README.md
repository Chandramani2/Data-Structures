# 🧠 Dynamic Programming Cheatsheet (C++)

A guide to mastering Dynamic Programming, focusing on identifying patterns, state transitions, and space optimization.

## 📖 Overview

**Dynamic Programming (DP)** is an optimization technique for solving recursive problems that have **Overlapping Subproblems** and **Optimal Substructure**.

Essentially: **DP = Recursion + Caching (Memoization)** or **Iterative Tabulation**.

### The Two Approaches

| Feature | Top-Down (Memoization) | Bottom-Up (Tabulation) |
| :--- | :--- | :--- |
| **Concept** | Recursion with caching results. | Iterative loop filling a table. |
| **Ease** | Easier to implement (natural logic). | Harder to think of transition initially. |
| **Space** | Stack memory + Cache ($O(N)$). | Heap memory only ($O(N)$). |
| **Speed** | Can be slower due to recursion overhead. | Faster (CPU cache friendly). |
| **Optimization**| Hard to space-optimize. | Easy to Space Optimize ($O(1)$ usually). |

---

## 🛠 1. The 1D DP Pattern
**Use case:** Climbing Stairs, Fibonacci, House Robber.
**State:** `dp[i]` depends on `dp[i-1]`, `dp[i-2]`, etc.

### Climbing Stairs (Count ways to reach N)
```cpp
// Space Optimized Bottom-Up
int climbStairs(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

## 🎒 2. Knapsack Pattern (0/1)
**Use case:** Selecting items with weight/value constraints to maximize value.
**State:** `dp[index][remaining_weight]`

### 0/1 Knapsack (Item can be picked once)
```cpp
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // dp[w] = max value with capacity w (1D array optimization)
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        // Iterate backwards to avoid using same item multiple times for same weight
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}
```
*Note: For **Unbounded Knapsack** (infinite supply), iterate `w` forward (`0` to `W`).*

---

## 🧵 3. String DP (LCS Pattern)
**Use case:** Longest Common Subsequence, Edit Distance, Palindromes.
**State:** `dp[i][j]` represents result for string `A[0...i]` and string `B[0...j]`.

### Longest Common Subsequence (LCS)
```cpp
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Skip
            }
        }
    }
    return dp[n][m];
}
```

---

## 📈 4. LIS Pattern
**Use case:** Longest Increasing Subsequence, Box Stacking.
**State:** `dp[i]` = length of LIS ending at index `i`.

```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int max_len = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        max_len = max(max_len, dp[i]);
    }
    return max_len; // O(N^2)
}
```

---

## 🗺️ 5. Grid / Matrix DP
**Use case:** Min path sum, Unique paths in grid.
**State:** `dp[r][c]` depends on `dp[r-1][c]` (top) and `dp[r][c-1]` (left).

### Unique Paths
```cpp
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    // Base cases
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
```

---

## ⚡ Complexity Cheatsheet

| Pattern | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Fibonacci / 1D** | $O(N)$ | $O(1)$ (Optimized) |
| **0/1 Knapsack** | $O(N \cdot W)$ | $O(W)$ (Optimized) |
| **LCS / Edit Dist** | $O(N \cdot M)$ | $O(\min(N, M))$ (Optimized) |
| **LIS** | $O(N^2)$ | $O(N)$ |
| **Matrix Path** | $O(R \cdot C)$ | $O(C)$ (Optimized) |