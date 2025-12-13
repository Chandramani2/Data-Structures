#include "bits/stdc++.h"
using namespace std;
/*  Undirected:
	Even Length cycle & Acyclic Graph - Bi-Partie
	odd length cycle - Not a Bi-Partie
*/

struct Edge{
	int dest;
	int weight;
};

class Graph{
	private:
		int V;
		bool isDirected;
		vector<Edge> *adj;
	public:
		Graph(int V, bool directed = false){
			this->V = V;
			isDirected = directed;
			adj = new vector<Edge>[V];
		}

  	// Add Edge function
    void addEdge(int src, int dest, int weight = 1) {
        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            cout << "Error: Vertex index out of bounds." << endl;
            return;
        }
        Edge newEdge = {dest, weight};
        adj[src].push_back(newEdge);
        if(!isDirected){
        	adj[dest].push_back({src, weight});
        }
    }

    // Check BiPartie
    bool isBiPartie(int src){
    	// color : 0-> No color Assigned/Not visited, 1-> Red, 2:Green
    	vector<int>col(V,0);
    	queue<int>q;
    	q.push(src);
    	col[src] = 1; // Assigning color Red to 0
    	while(!q.empty()){
    		int node = q.front();
    		q.pop();
    		// Iterate over neighbors
            for (const auto& edge : adj[node]) {
               
                // Case 1: Neighbor is not colored yet
                if (col[edge.dest] == 0) {
                    // Assign opposite color
                    // If node is 1, neighbor becomes 2. If node is 2, neighbor becomes 1.
                    col[edge.dest] = (col[node] == 1) ? 2 : 1;
                    q.push(edge.dest);
                }
                
                // Case 2: Neighbor is already colored, check for conflict
                else if (col[edge.dest] == col[node]) {
                    return false; // Conflict found, not bipartite
                }
            }
        }
        return true;
        
    }

    // Display the Adjacency List
    void display() {
        cout << "\n--- Adjacency List ---" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ":";
            for (const auto& edge : adj[i]) {
                cout << " -> (" << edge.dest << ", w:" << edge.weight << ")";
            }
            cout << endl;
        }
        cout << "----------------------" << endl;
    }

};
int main()
{
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

    //4. Bi-Partie
    cout<<"is-BiPartie: "<<g.isBiPartie(0);
	
	return 0;
}
