import java.util.LinkedList;

/**
 * Digraph
 */
public class Digraph {

    private final int V;
    public LinkedList<Integer>[] adj;

    public Digraph(int V){

        this.V = V;
        adj = (LinkedList<Integer>[]) new LinkedList[V];

        for(int i = 0 ; i < V ; i++)
            adj[i] = new LinkedList<Integer>();

    }

    public void addEdge(int v , int w){

        adj[v].add(w);

    }

    public int V(){

        return this.V;

    }

    public Iterable<Integer>adj(int v){

        return adj[v];

    }

    public void printGraph(){

        for (int i = 0; i < V; i++) {
            for (Integer w : adj[i]) {
                System.out.println(i + " - " + w);
            }
        }

    }

    public static void main(String[] args) {
        
        System.out.println("Hello World");

        Digraph G = new Digraph(7);

        G.addEdge(0,2);
        G.addEdge(0,5);
        G.addEdge(0, 4);
        G.addEdge(6, 0);
        G.addEdge(3, 6);
        G.addEdge(3, 4);
        G.addEdge(3, 5);
        G.addEdge(3, 4);
        G.addEdge(6, 4);
        G.addEdge(1, 4);

        G.printGraph();

    }

}