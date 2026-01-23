import java.util.*;

public class GraphList {
    private int V;
    private boolean isDirected;
    private List<List<Edge>> adjList;
    public GraphList(int V) {
        this.V = V;
        this.isDirected = false;
        this.adjList = new ArrayList<>(V);
        // Initialize each list for the vertices
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
    }
    public GraphList(int V, boolean isDirected) {
        this.V = V;
        this.isDirected = isDirected;
        this.adjList = new ArrayList<>(V);
        // Initialize each list for the vertices
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    // Overloaded addEdge for default weight of 1
    public void addEdge(int src, int dest) {
        addEdge(src, dest, 1);
    }

    public void addEdge(int src, int dest, int weight) {
        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            System.out.println("Error: Vertex index out of bounds.");
            return;
        }

        adjList.get(src).add(new Edge(dest, weight));
        if (!isDirected) {
            adjList.get(dest).add(new Edge(src, weight));
        }
    }

    public void display() {
        System.out.println("\n--- Adjacency List ---");
        for (int i = 0; i < V; i++) {
            System.out.print("Vertex " + i + ":");
            for (Edge edge : adjList.get(i)) {
                System.out.print(" -> (" + edge.dest + ", w:" + edge.weight + ")");
            }
            System.out.println();
        }
        System.out.println("----------------------");
    }

    // Breadth-First Search (BFS)
    public void BFS(int startVertex) {
        if (startVertex < 0 || startVertex >= V) return;

        boolean[] visited = new boolean[V];
        Queue<Integer> queue = new LinkedList<>();

        visited[startVertex] = true;
        queue.add(startVertex);

        System.out.print("BFS Traversal starting from " + startVertex + ": ");

        while (!queue.isEmpty()) {
            int curr = queue.poll();
            System.out.print(curr + " ");

            for (Edge edge : adjList.get(curr)) {
                if (!visited[edge.dest]) {
                    visited[edge.dest] = true;
                    queue.add(edge.dest);
                }
            }
        }
        System.out.println();
    }

    // Depth-First Search (DFS)
    public void DFS(int startVertex) {
        if (startVertex < 0 || startVertex >= V) return;

        boolean[] visited = new boolean[V];
        System.out.print("DFS Traversal starting from " + startVertex + ": ");
        dfsRecursiveHelper(startVertex, visited);
        System.out.println();
    }

    private void dfsRecursiveHelper(int currentVertex, boolean[] visited) {
        visited[currentVertex] = true;
        System.out.print(currentVertex + " ");

        for (Edge edge : adjList.get(currentVertex)) {
            if (!visited[edge.dest]) {
                dfsRecursiveHelper(edge.dest, visited);
            }
        }
    }
}

