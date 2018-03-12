/**
 * EdgeWeightedDigraph
 */
public class EdgeWeightedDigraph {

    private final int V;
    private Bag<DirectedEdge>[] adj;

    public EdgeWeightedDigraph(int V){

        this.V = V;

        adj = (Bag<DirectedEdge>[]) new Bag[V];

        for (int i = 0; i < V; i++) {
            adj[i] = new Bag<DirectedEdge>();
        }

    }

    public void addEdge(DirectedEdge e){

        int source = e.from();

        adj[source].add(e);

    }

    public int V(){

        return this.V;

    }

    public Iterable<DirectedEdge> adj(int v){

        return adj[v];

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

        //DijkstraSP DSP = new DijkstraSP(G, 0);

        //DSP.printSP();

        //TopologicalSP TSP = new TopologicalSP(G, 0);

        //TSP.printSP();

        BellManFordSP BSP = new BellManFordSP(G, 0);

        BSP.printSP();

    }

}