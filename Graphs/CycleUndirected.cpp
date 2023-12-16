#include<bits/stdc++.h>
using namespace std;

class Graph{

	public:
	int V;
	list<int> *adj;
	
	Graph(int V){
		this->V=V;
		adj = new list<int>[V+1];
	}

	void addEdge( int s, int d){
		adj[s].push_back(d);
	  	adj[d].push_back(s);
	}

	void printGraph() {
	   for (int v = 0; v < V; ++v) {
        cout << "Adjacency list of vertex " << v << ":\n";
        for (const auto& neighbor : adj[v]) {
            std::cout << " -> " << neighbor;
        }
    	cout << std::endl;
    	}
    }

    void DFS(int src,int visited[]){
		if(visited[src]) return;
		visited[src] = 1;
	 	cout<<src<< " ";
		for(int v: adj[src]){
	     if(!visited[v])
				DFS(v,visited);
		}
	}

	bool detectCycle(int src, int visited[], int parent){
		
		visited[src] = 1;
		for(int v: adj[src]){
	     	if(!visited[v]){
				if(detectCycle(v,visited,src)) return true;
			}
			else if(v!=parent) return true;
		}
		return false;
	}

};


int main(){

	int V = 8;
	Graph g(V);
	g.addEdge(1,5);
	g.addEdge(1,3);
	g.addEdge(3,4);
	g.addEdge(4,6);
	g.addEdge(5,6);
	g.addEdge(4,7);
	g.addEdge(7,8);
 	// g.printGraph();
 	int visited[V+1] = {0};
	// g.DFS(1,visited);
	bool ans = false;
	for(int i=1; i<=V;i++){
		if(!visited[i])
			ans = g.detectCycle(i,visited,i);
		if(ans) break;
		
	}
	if(ans) cout<<"There is Cycle";
	if(!ans) cout<<"There is No Cycle Present";
	return 0;
}