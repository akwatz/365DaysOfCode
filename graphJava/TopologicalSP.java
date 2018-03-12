import java.util.Stack;

//Programm to compute shortes path in a weighted DAG
//weights may be negative
//but the graph can't contain cycle

/**
 * TopologicalSP
 */
public class TopologicalSP {

    private int[] topologicalOrder;         //store topological order
    private final int source;               //source vertex
    private final int V;                    //number of vertices
    private Double distTo[];                //store the distance from source
    private DirectedEdge[] edgeTo;          //store the last edge to the node
    private boolean[] visited;              //visited array
    private Stack<Integer> stack;           //stack to store the postorder traversal


    //public constructor
    public TopologicalSP(EdgeWeightedDigraph G , int s){

        //--------------INTIALIZATION----------//

        V = G.V();
        source = s;

        topologicalOrder = new int[G.V()];
        distTo = new Double[G.V()];
        edgeTo = new DirectedEdge[G.V()];
        visited = new boolean[G.V()];

        stack = new Stack<Integer>();

        //set the distance to every node infinity

        for (int i = 0; i < G.V(); i++) {
            distTo[i] = Double.POSITIVE_INFINITY;
        }

        //get the topological order

        toplogicalSort(G);

        distTo[s] = 0.0;

        //relax all edges coming from the verteices in topological order
        for (int i = 0; i < G.V(); i++) {
            for (DirectedEdge e : G.adj(topologicalOrder[i])) {
                relax(e);                
            }
        }

    }

    // function to get the topological traversal of the graph
    private void toplogicalSort(EdgeWeightedDigraph G){

        //visit the nodes if not visited
        //get the post order traversal
        for (int i = 0; i < G.V(); i++) {
            if(visited[i])
                continue;
            visit(G,i);
        }

        int i = 0 ;

        //reverse the post order traversal
        while(!stack.isEmpty()){

            topologicalOrder[i++] = stack.pop();

        }

    }

    //function to visit the nodes
    private void visit(EdgeWeightedDigraph G , int parent){

        //if visited then return
        if(visited[parent])
            return;

        //make it visited
        visited[parent] = true;

        //visit all the children
        for (DirectedEdge e : G.adj(parent)) {
            visit(G , e.to());
        }

        //push the parent after visiting children
        stack.push(parent);

    }


    //function to relax the edges
    private void relax(DirectedEdge e){

        int v = e.to() , w = e.from();

        if(distTo[v] > distTo[w] + e.weight()){

            distTo[v] = distTo[w] + e.weight();
            edgeTo[v] = e;

        }

    }

    //function to print the shortest path
    public void printSP(){

        for (int i = 0; i < V; i++) {
            System.out.print(topologicalOrder[i] + " ");
        }

        System.out.println();

        for (int i = 0; i < this.V; i++) {
            
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