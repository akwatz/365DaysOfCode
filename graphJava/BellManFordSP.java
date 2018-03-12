//Program to compute the shortest path using bellman
//ford algorithm. It works for graph with negative weights
//graph with cycles
//but fails with graph having negative cycles

/**
 * BellManFordSP
 */
import java.util.Stack;
import java.util.*;
import java.io.*;

public class BellManFordSP {

    private final int source; //source node
    private final int V; //number of vertices
    private Double[] distTo; //array to store the distance of vertices
    private DirectedEdge edgeTo[]; //array to store the last edge to the node

    public BellManFordSP(EdgeWeightedDigraph G, int s) {

        this.source = s;
        this.V = G.V();

        distTo = new Double[V];
        edgeTo = new DirectedEdge[V];

        for (int i = 0; i < V; i++) {
            distTo[i] = Double.POSITIVE_INFINITY;
        }

        distTo[source] = 0.0;

        for (int i = 0; i < V; i++) {
            for (DirectedEdge e : G.adj(i)) {
                relax(e);
            }
        }

    }

    //function to relax the edges
    private void relax(DirectedEdge e) {

        int v = e.to(), w = e.from();

        if (distTo[v] > distTo[w] + e.weight()) {

            distTo[v] = distTo[w] + e.weight();
            edgeTo[v] = e;

        }

    }

    //function to print the shortest path
    public void printSP() {

        System.out.println();

        for (int i = 0; i < this.V; i++) {

            if (i == source)
                continue;

            System.out.println("Path between " + source + " and " + i);
            System.out.println(distTo[i]);

            System.out.println("Path");

            Stack<Integer> s = new Stack<Integer>();

            DirectedEdge temp = edgeTo[i];

            s.push(i);

            while (temp.from() != source) {

                s.push(temp.from());
                temp = edgeTo[temp.from()];

            }
            s.push(source);

            while (!s.isEmpty()) {

                System.out.print(s.pop());

            }

            System.out.println();

        }

    }

}