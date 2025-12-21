# 🕸️ Graph Theory Cheatsheet (C++)

A comprehensive guide to Graph algorithms, representations, and common patterns for competitive programming and software engineering interviews.

## 📖 Overview

A Graph consists of a finite set of **Vertices (Nodes)** and **Edges** connecting them.
* **Directed vs Undirected:** One-way vs Two-way streets.
* **Weighted vs Unweighted:** Edges have costs (weights) vs all edges are equal.
* **Cyclic vs Acyclic:** Contains a loop vs no loops (Tree/DAG).

---

## 🛠 Graph Representations

### 1. Adjacency List (Most Common)
Best for sparse graphs. Space: $O(V + E)$.

```cpp
// V = Number of vertices
// Unweighted
vector<vector<int>> adj(V); 
adj[u].push_back(v); 
adj[v].push_back(u); // If undirected

// Weighted (Pair: {neighbor, weight})
vector<vector<pair<int, int>>> adj(V);
adj[u].push_back({v, weight});
```

### 2. Adjacency Matrix
Best for dense graphs or small $V$ ($V < 1000$). Space: $O(V^2)$. Fast lookup $O(1)$.

```cpp
int adj[V][V]; 
adj[u][v] = 1; // Or weight
adj[v][u] = 1; // If undirected
```

---

## 🔍 Traversals
The backbone of almost all graph problems. Time Complexity: $O(V + E)$.

### 1. Breadth-First Search (BFS)
**Use case:** Shortest path in unweighted graphs, Level order traversal.
**Data Structure:** `std::queue`

```cpp
void bfs(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
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

### 2. Depth-First Search (DFS)
**Use case:** Cycle detection, Path finding, Topological Sort, Connected Components.
**Data Structure:** `std::stack` (or Recursion).

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}
```

---

## 🛣️ Shortest Path Algorithms

### 1. Dijkstra’s Algorithm
**Use case:** Shortest path in **Weighted** graphs (Non-negative weights).
**Complexity:** $O(E \log V)$

```cpp
vector<int> dijkstra(int start, int V, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(V, INT_MAX);
    // Min-heap priority queue: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue; // Skip outdated entries

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

### 2. Bellman-Ford
**Use case:** Weighted graphs with **Negative weights** (Detects negative cycles).
**Complexity:** $O(V \cdot E)$

---

## 🧩 Topological Sort
**Use case:** Scheduling tasks, Dependency resolution (DAGs only).

### Kahn’s Algorithm (BFS based)
1. Calculate in-degree for all nodes.
2. Push nodes with `0` in-degree to Queue.
3. Process queue: remove node, decrease neighbor in-degrees. If neighbor becomes `0`, push to queue.

```cpp
vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
    vector<int> in_degree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) in_degree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) q.push(i);

    vector<int> result;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) q.push(v);
        }
    }
    return result;
}
```

---

## 🔗 Disjoint Set Union (DSU)
**Use case:** Kruskal's MST, Cycle Detection in Undirected Graph, Dynamic Connectivity.
**Complexity:** $O(\alpha(N))$ (Nearly constant).

```cpp
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }
    
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path Compression
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i; // Union by Rank
            if (rank[root_i] == rank[root_j]) rank[root_i]++;
        }
    }
};
```

---

## ⚡ Complexity Cheatsheet

| Algorithm | Time Complexity | Space Complexity | Use Case |
| :--- | :--- | :--- | :--- |
| **BFS/DFS** | $O(V + E)$ | $O(V)$ | Traversal, Connectivity |
| **Dijkstra** | $O(E \log V)$ | $O(V + E)$ | Weighted Shortest Path (+ve) |
| **Bellman-Ford**| $O(V \cdot E)$ | $O(V)$ | Negative Weights |
| **Floyd-Warshall**| $O(V^3)$ | $O(V^2)$ | All-Pairs Shortest Path |
| **Kruskal's/Prim's**| $O(E \log E)$ | $O(V + E)$ | Minimum Spanning Tree |
| **Topological Sort**| $O(V + E)$ | $O(V)$ | Dependency Order |

# A* Pathfinding Algorithm Implementation in C++

This document explains the provided C++ implementation of the **A* (A-Star) Search Algorithm**. A* is a heuristic-based pathfinding algorithm widely used in robotics and game development to find the shortest path between two points on a grid.

---

## 1. Data Structures

### The `Node` Struct
A `Node` represents a single coordinate on the grid. It tracks the mathematical components required for the A* formula:

* **Coordinates**: `x` and `y` represent the position in the 2D grid.
* **Costs**:
    * $g$: The cost from the start node to the current node.
    * $h$ (Heuristic): The estimated cost from the current node to the goal.
    * $f$: The total estimated cost ($f = g + h$).
* **Parent**: A `shared_ptr` to the previous node. This creates a "breadcrumb" trail used to reconstruct the path once the goal is found.
* **Comparison Operator**: Overloads `>` to allow the `priority_queue` to act as a **min-heap**, ensuring the node with the lowest $f$ value is processed first.

---

## 2. Heuristics Class
The `Heuristics` class provides different ways to estimate the distance to the goal:

1.  **Manhattan Distance**: Used for 4-directional movement (Up, Down, Left, Right). It calculates the sum of absolute differences of coordinates.
    > $dist = |x_1 - x_2| + |y_1 - y_2|$
2.  **Euclidean Distance**: Used when diagonal or any-angle movement is allowed. It calculates the straight-line distance.
    > $dist = \sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2}$



---

## 3. The AStarSearch Class logic

### Core Search Logic (`findPath`)
The algorithm explores the grid by maintaining two primary collections:
* **Open List**: A priority queue of nodes to be explored.
* **Closed List**: A 2D boolean array (`closedList`) to track nodes that have already been evaluated, preventing infinite loops.

#### The Process:
1.  **Initialize**: Calculate the heuristic for the starting cell and add it to the Open List.
2.  **Iterate**: 
    * Extract the node with the lowest $f$ cost from the Open List.
    * If the node is the **Goal**, stop and print the path.
    * If not, mark it as "closed."
3.  **Neighbor Expansion**: Look at the 4 adjacent cells (Up, Down, Left, Right).
    * **Validation**: Ensure the neighbor is within bounds, is not a wall (`1`), and hasn't been visited.
    * **Calculation**: If valid, create a new node, update its $g$ cost ($current.g + 1$), calculate its $h$ cost, and push it to the Open List.

### Helper Functions
* `isValid()`: Checks if a coordinate is within the matrix boundaries.
* `printPath()`: Follows the `parent` pointers from the goal back to the start, reverses the list, and prints the coordinates.

---

## 4. Main Function Execution
The `main` function defines a grid where:
* `0`: Walkable path.
* `1`: Obstacle (Wall).

The search starts at `(0, 0)` and targets `(4, 4)`. The algorithm efficiently maneuvers around the walls (like the one at `(1, 0)`) to find the optimal route.

---

## 5. Potential Improvements
* **Memory Management**: Currently, the code creates many `shared_ptr<Node>` objects. For very large maps, a pre-allocated pool of nodes would be faster.
* **Diagonal Movement**: To allow diagonal movement, you can expand the `dx` and `dy` arrays to 8 directions and use the Euclidean heuristic.
* **Euclidean Bug Fix**: In the provided code, the Euclidean formula accidentally uses `x1 - x2` twice. It should be:
    ```cpp
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    ```