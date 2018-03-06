import java.util.Stack;

/**
 * ReversePostOrder
 */
public class ReversePostOrder {

    public int[] traversal;

    private Stack<Integer> dfs;

    private boolean visited[];

    private int counter = 0;

    public ReversePostOrder(Digraph G){

        dfs = new Stack<Integer>();
        traversal = new int[G.V()];
        visited = new boolean[G.V()];

        for (int i = 0; i < G.V(); i++) {
            dfs(G , i);
        }

        while(!dfs.empty()){

            traversal[counter++] = dfs.pop();

        }

    }

    private void dfs(Digraph G , int parent){

        if(visited[parent])
            return;

        visited[parent] = true;

        for (Integer w : G.adj[parent]) {
            dfs(G , w);
        }

        dfs.push(parent);

    }

}