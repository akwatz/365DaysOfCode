import java.util.Stack;

/**
 * DijkstraSP
 */
public class DijkstraSP {

    private DirectedEdge edgeTo[];
    private double distTo[];
    private IndexMinPQ<Double> pq;
    private final int source;
    private final int size;

    public DijkstraSP(EdgeWeightedDigraph G , int s){

        edgeTo = new DirectedEdge[G.V()];
        distTo = new double[G.V()];
        pq = new IndexMinPQ<Double>(G.V());
        source = s;
        size = G.V();

        for (int i = 0; i < G.V(); i++) {
            distTo[i] = Double.POSITIVE_INFINITY;
        }

        distTo[s] = 0.0;

        pq.insert(s , 0.0);

        while(!pq.isEmpty()){

            int v = pq.delMin();

            for (DirectedEdge w : G.adj(v)) {
                relax(w);
            }

        }

    }

    private void relax(DirectedEdge e){

        int v = e.from() , w = e.to();

        if(distTo[w] > distTo[v] + e.weight()){

            distTo[w] = distTo[v] + e.weight();
            edgeTo[w] = e;

            if(pq.contains(w)){

                pq.decreaseKey(w , distTo[w]);

            }
            else    
                pq.insert(w , distTo[w]);

        }

    }

    public void printSP(){

        for (int i = 0; i < size; i++) {
            
            if(i == source)
                continue;

            System.out.println("Path between " + source + " and " + i);
            System.out.println(distTo[i]);

            System.out.println("Path");

            Stack<Integer> s = new Stack<Integer>();

            DirectedEdge temp = edgeTo[i];

            s.push(i);

            while(temp.from() != source){

                s.push(temp.from());
                temp = edgeTo[temp.from()];

            }
            s.push(source);

            while(!s.isEmpty()){

                System.out.print(s.pop());

            }

            System.out.println();

        }

    }

}