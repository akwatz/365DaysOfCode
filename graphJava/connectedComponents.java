import java.io.*;
import java.util.*;

/**
 * connectedComponents
 */

public class connectedComponents {

    private int[] id;
    private boolean visited[];
    private int count;

    private void dfs(Graph G , int v){

        visited[v] = true;
        id[v] = count;
        
        for (int w : G.adj[v]) {

            if(!visited[w])
                dfs(G,w);
            
        }

    }

    public connectedComponents(Graph G){

        visited = new boolean[G.V()];
        id = new int[G.V()];

        for (int i = 0; i < G.V(); i++) {
            
            visited[i] = false;

        }
        
        for(int i = 0 ; i < G.V() ; i++){

            if(!visited[i]){

                dfs(G,i);
                count++;

            }

        }

    }

    public int count(){

        return count;

    }

    public boolean isConnected(int v , int w) {

        return id[v] == id[w];
        
    }

    public static void main(String[] args) {
        
        System.out.println("Hello World");

        Graph G = new Graph(10);

        G.addEdge(1,2);
        G.addEdge(1,3);
        G.addEdge(1,4);
        G.addEdge(1,5);
        G.addEdge(7,8);
        G.addEdge(8,9);
        G.addEdge(9,6);
        G.addEdge(0,4);
        G.addEdge(0,5);
        G.addEdge(4,3);
        G.addEdge(4,2);

        connectedComponents CC = new connectedComponents(G);

        System.out.println(CC.isConnected(1,2));
        System.out.println(CC.isConnected(1,3));
        System.out.println(CC.isConnected(0,3));
        System.out.println(CC.isConnected(9,6));
        System.out.println(CC.isConnected(1,9));
        System.out.println(CC.isConnected(5,6)); 

        System.out.println(CC.count);

    }

}