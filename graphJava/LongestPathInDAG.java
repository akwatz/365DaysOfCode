import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * Programm to find the longest path in DAG
 */

/**
 * LongestPathInDAG
 */
public class LongestPathInDAG {

    Queue<Integer> topOrder;
    Double DistTo[];
    DirectedEdge EdgeTo[];

    public LongestPathInDAG(EdgeWeightedDigraph G , int src){

        topOrder = new LinkedList<Integer>();

        Stack<Integer> postOrder = new Stack<Integer>();

        getPostOrder(G , postOrder);

        while(!postOrder.isEmpty()){

            topOrder.add(postOrder.pop());

        }

        DistTo = new Double[G.V()];
        EdgeTo = new DirectedEdge[G.V()];

        for (int i = 0; i < G.V(); i++) {
            DistTo[i] = Double.NEGATIVE_INFINITY;
        }

        DistTo[src] = 0.0;

        while(!topOrder.isEmpty()){

            longestPath(G , topOrder.poll());

        }


    }

    public void longestPath(EdgeWeightedDigraph G , int vertex){

        for (DirectedEdge e : G.adj(vertex)) {
            relaxEdge(e);
        }  

    }

    void relaxEdge(DirectedEdge e){

        int src = e.from();
        int dst = e.to();

        if( DistTo[dst] < DistTo[src] + e.weight() ){

            DistTo[dst] = DistTo[src] + e.weight();
            EdgeTo[dst] = e;

        }

    }

    public void getPostOrder(EdgeWeightedDigraph G , Stack<Integer> postOrder){

        boolean visited[] = new boolean[G.V()];

        for (int i = 0; i < G.V(); i++) {
            visit(G , i , visited , postOrder);            
        }

    }

    public void visit(EdgeWeightedDigraph G , int parent , boolean visited[] , Stack<Integer> postOrder){

        if(visited[parent])
            return;

        visited[parent] = true;

        for (DirectedEdge e : G.adj(parent)) {
            visit(G , e.to() , visited , postOrder);
        }

        postOrder.push(parent);

    }

    public static void main(String[] args) {

        EdgeWeightedDigraph G = new EdgeWeightedDigraph(8);

        G.addEdge(new DirectedEdge(0, 1, 5));
        G.addEdge(new DirectedEdge(0, 7, 8));
        G.addEdge(new DirectedEdge(0, 4, 9));
        G.addEdge(new DirectedEdge(1, 3, 15));
        G.addEdge(new DirectedEdge(1, 2, 12));
        G.addEdge(new DirectedEdge(1, 7, 4));
        G.addEdge(new DirectedEdge(2, 3, 3));
        G.addEdge(new DirectedEdge(2, 6, 11));
        G.addEdge(new DirectedEdge(3, 6, 9));
        G.addEdge(new DirectedEdge(4, 5, 4));
        G.addEdge(new DirectedEdge(4, 6, 20));
        G.addEdge(new DirectedEdge(4, 7, 5));
        G.addEdge(new DirectedEdge(5, 2, 1));
        G.addEdge(new DirectedEdge(5, 6, 13));
        G.addEdge(new DirectedEdge(7, 2, 7));
        G.addEdge(new DirectedEdge(7, 5, 6));

    }

}