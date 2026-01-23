import java.util.Arrays;

public class GraphMatrix {
    private int V;
    private boolean isDirected;
    private int[][] adjMatrix;

    public GraphMatrix(int V) {
        this.V = V;
        this.isDirected = false;
        adjMatrix = new int[V][V];
    }
    public GraphMatrix(int V, boolean isDirected) {
        this.V = V;
        this.isDirected = isDirected;
        adjMatrix = new int[V][V];
    }
    // In Java cannot pass value in method parameters so that's why we have to use
    // method overloading otherwise we have to pass 'w' everytime
    public void addEdge(int src, int dest) {
       addEdge(src, dest, 1);
    }

    public void addEdge(int src, int dest, int w) {
        if(src < 0 || src > V || dest < 0 || dest > V){
            System.out.println("Error: Vertex index out of bounds.");
            return;
        }
        adjMatrix[src][dest] = w;
        if(!isDirected) adjMatrix[dest][src] = w;
    }

    public void removeEdge(int src, int dest) {
        if(src < 0 || src > V || dest < 0 || dest > V) return;
        adjMatrix[src][dest] = 0;
        if(!isDirected) adjMatrix[dest][src] = 0;
    }
    public void printGraph() {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                System.out.print(adjMatrix[i][j] + " ");
            }
            System.out.println();
        }
//        Arrays.stream(adjMatrix).forEach(x -> System.out.print(Arrays.toString(x) + " "));
    }
}
