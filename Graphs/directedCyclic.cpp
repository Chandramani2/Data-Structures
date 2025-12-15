#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int dest;
    int weight;
};

class Graph {
    int V;
    bool isDirected;
    vector<vector<Edge>> adjList;

public: 
    Graph(int V, bool directed = false) {
        this->V = V;
        isDirected = directed;
        adjList.resize(V);
    }

    void addEdge(int src, int dest, int weight = 1) {
        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            cout << "Error: Vertex index out of bounds." << endl;
            return;
        }
        Edge newEdge = {dest, weight};
        adjList[src].push_back(newEdge);
        
        if (!isDirected) {
            Edge reverseEdge = {src, weight};
            adjList[dest].push_back(reverseEdge);
        }
    }

    // We need two arrays: 'vis' (visited globally) and 'recStack' (in current recursion path)
    bool DFS(int src, vector<bool>& vis, vector<bool>& recStack) {
        vis[src] = true;
        recStack[src] = true; // Mark node in recursion stack

        for (const auto& edge : adjList[src]) {
            int neighbor = edge.dest; 

            // If neighbor is not visited, recurse
            if (!vis[neighbor]) {
                if (DFS(neighbor, vis, recStack)) 
                    return true;
            }
            // If neighbor is visited AND in recursion stack, we found a cycle (Back Edge)
            else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[src] = false; // Remove node from recursion stack (Backtracking)
        return false;
    }

    bool isCycle() {
        // Fix 5: Use vector instead of arrays (VLA is not standard C++)
        vector<bool> vis(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            // Only call DFS if the node hasn't been visited yet
            if (!vis[i]) {
                if (DFS(i, vis, recStack)) 
                    return true;
            }
        }
        return false;
    }
};

int main() {
    // Example: Create a directed graph with a cycle
    // Cycle: 0 -> 1 -> 2 -> 0
    Graph g(4, true);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0); // This creates the cycle
    g.addEdge(2, 3);

    if (g.isCycle()) {
        cout << "Cycle Detected" << endl;
    } else {
        cout << "No Cycle Found" << endl;
    }

    return 0;
}