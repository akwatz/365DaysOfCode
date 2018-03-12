/**
 * DirectedEdge
 */
public class DirectedEdge {

    private final int v , w;        //source and dest nodes
    private final double weight;    //weight of edge

    //public constructor
    public DirectedEdge(int v , int w , double weight){

        this.v = v;
        this.w = w;
        this.weight = weight;

    }

    //function to retrive source node
    public int from(){

        return v;

    }

    //function to retrieve dest node
    public int to(){

        return w;

    }

    //function to retrieve weight of the edge
    public double weight(){

        return this.weight;

    }

}