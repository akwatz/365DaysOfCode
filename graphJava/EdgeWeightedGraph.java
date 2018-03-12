import java.util.*;
import java.io.*;

/**
 * EdgeWeightedGraph
 */
public class EdgeWeightedGraph {

    private final int V;
    private Bag<Edge>[] adj;

    public EdgeWeightedGraph(int V){

        this.V = V;

        adj = (Bag<Edge>[]) new Bag[V];

        for (int i = 0; i < V; i++) {
            
            adj[i] = new Bag<Edge>();

        }

    }

    public void addEdge(Edge e){

        int v = e.either() , w = e.other(v);

        adj[v].add(e);
        adj[w].add(e);

    }

    public Iterable<Edge> adj(int v){

        return adj[v];

    }

    public int V(){return this.V;}

    public Iterable<Edge> edges(){

        Bag<Edge> list = new Bag<Edge>();

        for (int i = 0; i < V; i++) {

            int selfLoops = 0;
            for (Edge e : adj[i]) { 

                if(e.other(i) > i){
                    
                    list.add(e);
                }
                else if(e.other(i) == i){

                    if(selfLoops % 2 == 0)
                        list.add(e);

                    selfLoops++;

                }
            }
        }

        return list;

    }

    public static void main(String[] args) {
        
        EdgeWeightedGraph G = new EdgeWeightedGraph(8);

        G.addEdge(new Edge(5, 1, 0.32));
        G.addEdge(new Edge(5, 4, 0.35));
        G.addEdge(new Edge(5, 7, 0.28));
        G.addEdge(new Edge(1, 7, 0.19));
        G.addEdge(new Edge(1, 3, 0.29));
        G.addEdge(new Edge(1, 2, 0.36));
        G.addEdge(new Edge(3, 6, 0.52));
        G.addEdge(new Edge(3, 2, 0.17));
        G.addEdge(new Edge(6, 2, 0.40));
        G.addEdge(new Edge(6, 0, 0.58));
        G.addEdge(new Edge(6, 4, 0.93));
        G.addEdge(new Edge(4, 7, 0.37));
        G.addEdge(new Edge(4, 0, 0.38));
        G.addEdge(new Edge(0, 7, 0.16));
        G.addEdge(new Edge(0, 2, 0.26));

        KruskalMST mst = new KruskalMST(G);
        PrimsMST Pmst = new PrimsMST(G);

        for (Edge e : mst.edges()) {
            System.out.println(e.either() + " -> " + e.other(e.either()));
        }

        System.out.println("Printing Prims MST");

        for (Edge e : Pmst.mst()) {
            System.out.println(e.either() + " -> " + e.other(e.either()));
        }

    }

}