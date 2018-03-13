import java.util.LinkedList;
import java.util.Queue;

/**
 * Programm to solve the 
 * max flow problem using
 * Ford Fulkerson Algorithm
 */

 /**
  * FordFulkerson
  */
 public class FordFulkerson {
 
    private boolean[] visited;
    private FlowEdge[] edgeTo;
    private Double value;
    
    public FordFulkerson(FlowNetwork G , int src , int dest){

        value = 0.0;

        while(hasAugmentedPath(G , src , dest)){

            Double bottle = Double.POSITIVE_INFINITY;

            for (int tr = dest; tr != src; tr = edgeTo[tr].other(tr)) {
                bottle = Math.min(bottle, edgeTo[tr].residualCapacity(tr));
            }

            for (int tr = dest; tr != src; tr = edgeTo[tr].other(tr)) {
                edgeTo[tr].addResidualCapacity(tr, bottle);
            }

            value += bottle;

        }

    }

    private boolean hasAugmentedPath(FlowNetwork G , int src , int dest){

        visited = new boolean[G.V()];
        edgeTo = new FlowEdge[G.V()];

        Queue<Integer> queue = new LinkedList<Integer>();

        queue.add(src);

        visited[src] = true;

        while(!queue.isEmpty()){

            int v = queue.poll();

            for (FlowEdge e : G.adj(v)) {
                int w = e.other(v);

                if(e.residualCapacity(w) > 0 && !visited[w]){

                    visited[w] = true;
                    edgeTo[w] = e;

                    queue.add(w);

                }

            }

        }

        return visited[dest];

    }

    public Double value(){return this.value;}

 }