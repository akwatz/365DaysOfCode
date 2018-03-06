import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

//Program to find whether two components of a
//Digraph are strongly connnected

/**
 * SCC
 */
public class SCC {

    private boolean visited[];
    private int[] id;
    private int count;

    public SCC(Digraph G){

        visited = new boolean[G.V()];
        id = new int[G.V()];
        count = 0;

        ReversePostOrder ros = new ReversePostOrder(G.reverseGraph());

        for (Integer w : ros.traversal) {
            if(!visited[w]){

                dfs(G,w);
                count++;

            }
        }

    }

    public void dfs(Digraph G , int parent) {
        if(visited[parent])
            return;

        visited[parent] = true;

        id[parent] = count;

        for (Integer w : G.adj[parent]) {
            dfs(G,w);
        }
    }

    public boolean connected(int v , int w){

        return id[v] == id[w];

    }

    public static void main(String[] args) {
        Digraph G = new Digraph(13);
        
        G.addEdge(0, 1);
        G.addEdge(0, 5);
        G.addEdge(2, 0);
        G.addEdge(2, 3);
        G.addEdge(3, 5);
        G.addEdge(3, 2);
        G.addEdge(4, 2);
        G.addEdge(4, 3);
        G.addEdge(5, 4);
        G.addEdge(6, 0);
        G.addEdge(6, 4);
        G.addEdge(6, 8);
        G.addEdge(6, 9);
        G.addEdge(7, 6);
        G.addEdge(7, 9);
        G.addEdge(8, 6);
        G.addEdge(9, 10);
        G.addEdge(9, 11);
        G.addEdge(10, 12);
        G.addEdge(11, 12);
        G.addEdge(12, 9);
        G.addEdge(11, 4);

        SCC connectedComponents = new SCC(G);

        System.out.println(connectedComponents.connected(0, 6));
        System.out.println(connectedComponents.connected(0, 1));
        System.out.println(connectedComponents.connected(7, 8));
        System.out.println(connectedComponents.connected(9, 10));
        System.out.println(connectedComponents.connected(4, 9));
        System.out.println(connectedComponents.connected(0, 2));
        System.out.println(connectedComponents.connected(6, 8));
        System.out.println(connectedComponents.connected(7, 9));

    }

}