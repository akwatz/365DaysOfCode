import java.awt.LinearGradientPaint;
import java.util.PriorityQueue;
import java.util.Queue;
import java.lang.*;
import java.util.*;
import java.io.*;

/**
 * PrimsMST
 */
public class PrimsMST {

    private boolean[] visited;
    private Queue<Edge> mst;
    private PriorityQueue<Edge> minPQ;

    public PrimsMST(EdgeWeightedGraph G){

        visited = new boolean[G.V()];
        mst = new LinkedList<Edge>();
        minPQ = new PriorityQueue<Edge>();

        visit(G , 0);

        while(!minPQ.isEmpty() && mst.size() < G.V() - 1){

            Edge e = minPQ.poll();

            int v = e.either() , w = e.other(v);

            if(visited[v] && visited[w])
                continue;

            mst.add(e);

            if(!visited[v])
                visit(G , v);

            if(!visited[w])
                visit(G , w);

        }

    }

    private void visit(EdgeWeightedGraph G , int v){

        visited[v] = true;

        for (Edge w : G.adj(v)) {
            if(!visited[w.other(v)])
                minPQ.add(w);
        }

    }

    public Iterable<Edge> mst(){

        return mst;

    }

}