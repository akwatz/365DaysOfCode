import java.awt.LinearGradientPaint;
import java.util.PriorityQueue;
import java.util.Queue;
import java.lang.*;
import java.util.*;
import java.io.*;
/**
 * KruskalMST
 */
public class KruskalMST {

    public Queue<Edge> mst;

    public KruskalMST(EdgeWeightedGraph G){

        mst = new LinkedList<Edge>();

        PriorityQueue minPQ = new PriorityQueue<Edge>();

        for (Edge edge : G.edges()) {
            minPQ.add(edge);
        }

        weightedQuickUF UF = new weightedQuickUF(G.V());

        while(!minPQ.isEmpty() && mst.size() < G.V() - 1){

            Edge e = (Edge)minPQ.poll();

            int v = e.either() , w = e.other(v);

            if(!UF.connected(v, w)){
                
                UF.union(v, w);
                mst.add(e);

            }
        }

    }

    public Iterable<Edge> edges(){

        return mst;

    }

}