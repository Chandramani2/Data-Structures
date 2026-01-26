private static ArrayList<Integer> topoLogicalSort(Graph g) {
    int V = g.getV();
    ArrayList<Integer> topological = new ArrayList<>();

    boolean[] visited = new boolean[V+1];
    Arrays.fill(visited, false);

    for (int i = 1; i <= V; i++) {
        if(visited[i]) continue;
        DFS(g,i, visited, topological);
    }
    Collections.reverse(topological);
    return topological;
}

private static void DFS(Graph g, int s, boolean[] visited, ArrayList<Integer> topological) {
    if(visited[s]) return;
    visited[s] = true;

    // Before pushing s, apply DFS on all children
    for(Edge edge: g.getAdjList().get(s)){
        int v = edge.dest;
        DFS(g,v,visited,topological);
    }
    topological.add(s);
}

public static void main() {

    Graph g = new Graph(8, true);

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.addEdge(1,5);
    g.addEdge(5,8);

    g.addEdge(1,7);
    g.addEdge(7,6);

    g.display();

    ArrayList<Integer> topoSort = topoLogicalSort(g);
    System.out.println("TopoSort: " + topoSort);
}


