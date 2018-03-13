import java.util.prefs.BackingStoreException;

import java.util.*;
import java.io.*;

/**
 * API to represent the flow network
 */

 /**
  * FlowNetwork
  */
 public class FlowNetwork {
 
    private final int V;
    private Bag<FlowEdge> adj[]; 

    //public constructor
    public FlowNetwork(int V){

        this.V = V;
        adj = (Bag<FlowEdge>[]) new Bag[V];

        for (int i = 0; i < V; i++) {
            adj[i] = new Bag<FlowEdge>();
        }

    }

    public int V(){return this.V;}

    public void addEdge(FlowEdge e){

        int src = e.from();
        int dest = e.to();

        adj[src].add(e);        //forward edge
        adj[dest].add(e);       //backward edge

    }

    public Iterable<FlowEdge> adj(int v){

        return this.adj[v];

    }

    public static void main(String[] args) {
        
        FlowNetwork G = new FlowNetwork(8);

        G.addEdge(new FlowEdge(0, 1, 10.0));
        G.addEdge(new FlowEdge(0, 3, 5.0));
        G.addEdge(new FlowEdge(0, 5, 15.0));
        G.addEdge(new FlowEdge(1, 2, 9.0));
        G.addEdge(new FlowEdge(1, 4, 15.0));
        G.addEdge(new FlowEdge(1, 3, 4.0));
        G.addEdge(new FlowEdge(2, 7, 10.0));
        G.addEdge(new FlowEdge(2, 4, 15.0));
        G.addEdge(new FlowEdge(3, 4, 8.0));
        G.addEdge(new FlowEdge(3, 5, 4.0));
        G.addEdge(new FlowEdge(4, 6, 15.0));
        G.addEdge(new FlowEdge(4, 7, 10.0));
        G.addEdge(new FlowEdge(5, 6, 16.0));
        G.addEdge(new FlowEdge(6, 3, 6.0));
        G.addEdge(new FlowEdge(6, 7, 10.0));

        FordFulkerson ff = new FordFulkerson(G, 0, 7);

        System.out.println(ff.value());
        
    }

 }