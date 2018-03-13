import javax.lang.model.util.ElementScanner6;

/*

    API to represent the flow edge in a flow network

*/

/**
 * FlowEdge
 */
public class FlowEdge {

    private final int src , dest;       //source and destination vertices
    private final Double capacity;      //capacity of the edge
    private Double flow;                //traffic on the edge

    //public constructor 
    public FlowEdge(int src , int dest , Double capacity){

        this.src = src;
        this.dest = dest;
        this.capacity = capacity;
        this.flow = 0.0;

    }

    public int from(){return this.src;}      //returns the source vertex
        
    public int to(){return this.dest;}    //return the destination vertex

    public Double capacity(){return this.capacity;} //returns the capacity of the edge

    public Double flow(){return this.flow;}       //return the flow of the edge  

    //returns the other vertex of the edge
    public int other(int v){    

        if(this.src == v)
            return this.dest;

        else    
            return this.src;

    }

    //returns the residual capacity of the edge
    public Double residualCapacity(int v){

        if(this.src == v)                   //backward edge
            return this.flow;

        else                                //forward edge
            return this.capacity - this.flow;

    }

    //updates the residual capacity of the edge
    public void addResidualCapacity(int v , Double delta){

        if(this.src == v){          //backward edge

            this.flow -= delta;

        }

        else {                      //forward edge

            this.flow += delta;

        }

    }

}