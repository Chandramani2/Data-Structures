#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

// Structure to represent an edge (Destination Vertex, Weight)
struct Edge {
    int dest;
    int weight;
};

class Graph {
private:
    int numVertices;
    bool isDirected;
    // Adjacency List: A vector where each index represents a vertex.
    // Each element is a list (or vector) of Edge structures.
    vector<vector<Edge>> adjList;

    // Recursive helper for DFS
    void dfsRecursiveHelper(int currentVertex, vector<bool>& visited) {
        visited[currentVertex] = true;
        cout << currentVertex << " ";

        // Iterate specifically through the neighbors of the current vertex
        for (const auto& edge : adjList[currentVertex]) {
            if (!visited[edge.dest]) {
                dfsRecursiveHelper(edge.dest, visited);
            }
        }
    }

public:
    // Constructor
    Graph(int vertices, bool directed = false) {
        numVertices = vertices;
        isDirected = directed;
        // Resize the outer vector to hold 'vertices' number of lists
        adjList.resize(vertices);
    }

    // Add Edge function
    void addEdge(int src, int dest, int weight = 1) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            cout << "Error: Vertex index out of bounds." << endl;
            return;
        }

        // Add forward edge
        Edge newEdge = {dest, weight};
        adjList[src].push_back(newEdge);

        // If undirected, add the reverse edge
        if (!isDirected) {
            Edge reverseEdge = {src, weight};
            adjList[dest].push_back(reverseEdge);
        }
    }

    // Display the Adjacency List
    void display() {
        cout << "\n--- Adjacency List ---" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ":";
            for (const auto& edge : adjList[i]) {
                cout << " -> (" << edge.dest << ", w:" << edge.weight << ")";
            }
            cout << endl;
        }
        cout << "----------------------" << endl;
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

            // Iterate ONLY through actual neighbors
            // This makes BFS O(V + E) instead of O(V^2)
            for (const auto& edge : adjList[curr]) {
                if (!visited[edge.dest]) {
                    visited[edge.dest] = true;
                    q.push(edge.dest);
                }
            }
        }
        cout << endl;
    }

    // Depth-First Search (DFS)
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

    // 2. Add Edges (Same shape as the matrix example)
    // 0 -- 1
    // |    |
    // 3 -- 2 -- 4
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    // 3. Display Structure
    g.display();

    // 4. Perform Traversals
    g.BFS(0); 
    g.DFS(0);

    // 5. Test Weighted Directed Graph
    cout << "\n--- Weighted Directed Graph Test ---" << endl;
    Graph g2(3, true);
    g2.addEdge(0, 1, 10);
    g2.addEdge(1, 2, 20);
    g2.addEdge(2, 0, 30);

    g2.display();

    return 0;
}