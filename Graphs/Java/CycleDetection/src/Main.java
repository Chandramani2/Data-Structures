/* considering 1 based Graph */

private static boolean cycleDetection(Graph g) {
    int V = g.getV();
    boolean [] visited = new boolean[V+1];
    Arrays.fill(visited,false);

    boolean [] stack = new boolean[V+1];
    Arrays.fill(stack,false);

    for(int i=1; i<=V; i++){
        if(visited[i]) continue;
        stack[i]=true;
        boolean ch = cycleDetectDirected(g, i, stack, visited);
        stack[i]=false;
        if (ch) return true;
    }
    return false;
}

private static boolean cycleDetectDirected(Graph g, int u, boolean[] stack, boolean[] visited) {
    if(visited[u]) return false;
    visited[u] = true;
    for(Edge edge: g.getAdjList().get(u)){
        int v = edge.dest;
        // from u->v there is an edge
        if(stack[v]) {
            return true;
        }
        else{
            stack[v] = true;
            boolean ch = cycleDetectDirected(g, v, stack, visited);
            stack[v] = false;
            if(ch) return true;
        }
    }
    return false;
}


public static void main() {
    // 1. Create a Graph with 5 vertices, Undirected
    Graph g = new Graph(11, true);

    /*
                2 <--- 1 ---> 3 ------> 4
                |                       |        10---> 2, 10 ---> 6, 5 ---> 7, 11 ---> 3
                |                       |
                5 ---> 8 ---> 10 <---- 11
                |      |
                |       |
                6 ---> 7
     */
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 11);
    g.addEdge(2, 5);
    g.addEdge(5, 8);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
    g.addEdge(8, 7);
    g.addEdge(8, 10);
    g.addEdge(10, 9);
    g.addEdge(11, 10);

    g.addEdge(10, 6); // This is not forming cycle

    g.addEdge(11, 3); // This is forming cycle
    g.addEdge(10, 2); // This is forming cycle


    g.display();
    System.out.println( cycleDetection(g));

}







