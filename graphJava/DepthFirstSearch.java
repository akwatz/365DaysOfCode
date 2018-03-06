import java.lang.reflect.Array;

/**
 * DepthFirstSearch
 */
public class DepthFirstSearch {

    public int[] dfs;
    private boolean visited[];
    int counter = 0;

    DepthFirstSearch(Digraph G){

        dfs = new int[G.V()];
        visited = new boolean[G.V()];

        for (int i = 0; i < G.V(); i++) {
            dfs(G , i);
        }

    }
    DepthFirstSearch(Graph G){

        dfs = new int[G.V()];
        visited = new boolean[G.V()];

    }

    void dfs(Digraph G , int parent){

        if(visited[parent])
            return;

        visited[parent] = true;
        dfs[counter++] = parent;

        for (Integer w : G.adj[parent]) {
            dfs(G , w);
        }

    }

    void dfs(Graph G , int parent){

        if(visited[parent])
            return;

        visited[parent] = true;
        dfs[counter++] = parent;

        for (Integer w : G.adj[parent]) {
            dfs(G , w);
        }

    }

}