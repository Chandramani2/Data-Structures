#include "bits/stdc++.h"
using namespace std;
/*  Way 1: Adjacency Matrix
*/
class Graph {
private:
    int numVertices;
    bool isDirected;
    // 2D Vector for the Adjacency Matrix
    // matrix[i][j] stores the weight of the edge from i to j.
    // 0 indicates no edge.
    vector<vector<int>> matrix;

    // Helper function for Recursive DFS
    void dfsRecursiveHelper(int startVertex, vector<bool>& visited) {
        // Mark current node as visited and print
        visited[startVertex] = true;
        cout << startVertex << " ";

        // Traverse all columns (potential neighbors)
        for (int i = 0; i < numVertices; i++) {
            // If there is an edge (weight != 0) and not visited
            if (matrix[startVertex][i] != 0 && !visited[i]) {
                dfsRecursiveHelper(i, visited);
            }
        }
    }

public:
    // Constructor: Initialize matrix with 0s
    Graph(int vertices, bool directed = false) {
        numVertices = vertices;
        isDirected = directed;
        // Resize matrix to VxV and initialize with 0
        matrix.resize(vertices, vector<int>(vertices, 0));
    }

    // Add Edge function
    // For unweighted graphs, the weight defaults to 1
    void addEdge(int src, int dest, int weight = 1) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            cout << "Error: Vertex index out of bounds." << endl;
            return;
        }

        matrix[src][dest] = weight;

        // If undirected, mirror the edge
        if (!isDirected) {
            matrix[dest][src] = weight;
        }
    }

    // Remove Edge function
    void removeEdge(int src, int dest) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            return;
        }

        matrix[src][dest] = 0;

        if (!isDirected) {
            matrix[dest][src] = 0;
        }
    }

    // Check if an edge exists
    bool hasEdge(int src, int dest) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            return false;
        }
        return matrix[src][dest] != 0;
    }

    // Get the weight of an edge
    int getEdgeWeight(int src, int dest) {
        if (hasEdge(src, dest)) {
            return matrix[src][dest];
        }
        return 0; // Or return -1 or INT_MAX depending on requirements
    }

    // Display the Adjacency Matrix
    void display() {
        cout << "\n--- Adjacency Matrix ---" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << setw(3) << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "------------------------" << endl;
    }

    // Breadth-First Search (BFS)
    void BFS(int startVertex) {
        if (startVertex < 0 || startVertex >= numVertices) return;

        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS Traversal starting from " << startVertex << ": ";

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            // Check all potential neighbors in the row
            for (int i = 0; i < numVertices; i++) {
                // If edge exists and neighbor not visited
                if (matrix[curr][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    // Depth-First Search (DFS) - Recursive wrapper
    void DFS(int startVertex) {
        if (startVertex < 0 || startVertex >= numVertices) return;

        vector<bool> visited(numVertices, false);
        cout << "DFS Traversal starting from " << startVertex << ": ";
        dfsRecursiveHelper(startVertex, visited);
        cout << endl;
    }
};

int main() {
    // 1. Create a Graph with 5 vertices (0 to 4), Undirected
    int V = 5;
    Graph g(V, false); 

    // 2. Add Edges (Creating a shape, e.g., a simple house shape)
    // 0 -- 1
    // |    |
    // 3 -- 2 -- 4
    
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4); 

    // 3. Display the Matrix
    g.display();

    // 4. Perform Traversals
    g.BFS(0); // Expected: 0 1 3 2 4 (order may vary slightly based on iteration)
    g.DFS(0); // Expected: 0 1 2 3 4 or 0 1 2 4 3

    // 5. Test Weight and Directed features
    cout << "\n--- Weighted Directed Graph Test ---" << endl;
    Graph g2(3, true); // Directed
    g2.addEdge(0, 1, 10); // Edge 0->1 weight 10
    g2.addEdge(1, 2, 20); // Edge 1->2 weight 20
    g2.addEdge(2, 0, 30); // Edge 2->0 weight 30 (Cycle)
    
    g2.display();
    
    if(g2.hasEdge(0, 1)) cout << "Edge 0->1 exists with weight: " << g2.getEdgeWeight(0, 1) << endl;
    if(!g2.hasEdge(1, 0)) cout << "Edge 1->0 does not exist (correct for directed graph)" << endl;

    return 0;
}