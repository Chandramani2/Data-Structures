import lombok.Getter;

import java.util.ArrayList;

@Getter
public class Graph {
    private int V;
    boolean isDirected;
    private ArrayList<ArrayList<Edge>> adjList;

    public Graph(int V) {
        this.V = V;
        this.isDirected = false;
        adjList = new ArrayList<>(V+1);
        for (int i = 0; i <= V; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    public Graph(int V, boolean isDirected) {
        this.V = V;
        this.isDirected = isDirected;
        adjList = new ArrayList<>(V+1);
        for (int i = 0; i <= V; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    void addEdge(int src, int dest){
        addEdge(src, dest, 1);
    }
    void addEdge(int src, int dest, int w) {
        if(src<1|| src>=V+1 || dest<1 || dest>=V+1) {
            System.out.println("Error: Vertex index out of bounds.");
            return;
        }
        adjList.get(src).add(new Edge(dest, w));
        if(!isDirected){
            adjList.get(dest).add(new Edge(src, w));
        }
    }

    void display(){
        for(int i=0 ; i<=V; i++){
            System.out.print(i);
            for(Edge edge: adjList.get(i)){
                if(isDirected){
                    System.out.print(" -> " + edge.dest +",(W: "+ edge.weight + ")");
                }
                else{
                    System.out.print(" -> " + edge.dest);
                }

            }
            System.out.println();
        }
    }
}
