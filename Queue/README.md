# 🚶 Queue Cheatsheet (C++)

A comprehensive guide to the **Queue** data structure, including standard operations, Breadth-First Search (BFS), and variants like Deques and Heaps.

## 📖 Overview

A **Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. The first element added is the first one to be removed.

### Standard Library (`<queue>`)
```cpp
#include <queue>
std::queue<int> q;
```

---

## 🛠 Standard Operations
All basic operations are **$O(1)$**.

| Operation | Function | Description |
| :--- | :--- | :--- |
| **Push** | `q.push(val)` | Adds `val` to the **back**. |
| **Pop** | `q.pop()` | Removes the **front** element (returns void). |
| **Front** | `q.front()` | Returns reference to the **front** element. |
| **Back** | `q.back()` | Returns reference to the **last** element. |
| **Size** | `q.size()` | Returns the number of elements. |
| **Empty** | `q.empty()` | Returns `true` if queue is empty. |

---

## 🧠 Essential Algorithms & Variants

### 1. Breadth-First Search (BFS)
**Use Case:** Shortest path in unweighted graphs, Level-order traversal.

```cpp
void bfs(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " "; 

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

### 2. Double-Ended Queue (`std::deque`)
**Use Case:** Sliding Window Maximum.

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Stores INDICES
    vector<int> res;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove out of window
        if (!dq.empty() && dq.front() == i - k) dq.pop_front();
        
        // Remove smaller elements (Monotonic Decreasing Queue)
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        
        dq.push_back(i);
        if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}
```

### 3. Priority Queue (Heap)
**Use Case:** Dijkstra, K-th Largest Element.
**Ops:** Push/Pop $O(\log N)$, Top $O(1)$.

```cpp
// Max Heap (Default)
priority_queue<int> maxPQ; 

// Min Heap
priority_queue<int, vector<int>, greater<int>> minPQ;
```

---

## ⚡ Complexity Cheatsheet

| Structure | Operation | Time Complexity |
| :--- | :--- | :--- |
| **Queue** | Push/Pop | $O(1)$ |
| **Deque** | Push/Pop (Front/Back) | $O(1)$ |
| **Priority Queue** | Push/Pop | $O(\log N)$ |