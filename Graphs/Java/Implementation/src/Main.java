
public static void main() {
    GraphMatrix graphMatrix = new GraphMatrix(5);
    graphMatrix.addEdge(0, 1 );
    graphMatrix.addEdge(0, 2);
    graphMatrix.addEdge(1, 2);
    graphMatrix.addEdge(2, 3);
    graphMatrix.addEdge(3, 4);
    graphMatrix.addEdge(2, 4);
    graphMatrix.addEdge(1, 4);
    graphMatrix.printGraph();

    // 1. Create a Graph with 5 vertices, Undirected
    GraphList g = new GraphList(5, false);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.display();

    g.BFS(0);
    g.DFS(0);

    // 2. Test Weighted Directed Graph
    System.out.println("\n--- Weighted Directed Graph Test ---");
    GraphList g2 = new GraphList(3, true);
    g2.addEdge(0, 1, 10);
    g2.addEdge(1, 2, 20);
    g2.addEdge(2, 0, 30);

    g2.display();
}
