import java.io.*;
import java.util.*;

public class quickFind{

    private int[] id;

    public quickFind(int n){

        id = new int[n];

        for(int i = 0 ; i < n ; i++)
            id[i] = i;

    }

    public boolean connected(int p , int q) {

        return id[p] == id[q];
        
    }

    public void union(int p , int q){

        int pid = id[p];
        int qid = id[q];

        for(int i = 0 ; i < id.length ; i++)
            if(id[i] == pid)
                id[i] = qid;

    }
    
    public static void main(String[] args) {
        
        System.out.println("Hello World");

        quickFind disjoint = new quickFind(10);

        disjoint.union(0,5);
        disjoint.union(5,6);
        disjoint.union(1,7);
        disjoint.union(1,2);
        disjoint.union(3,4);
        disjoint.union(3,8);
        disjoint.union(8,9);

        System.out.println(disjoint.connected(1,7));

        disjoint.union(2,3);

        System.out.println(disjoint.connected(0,5));
        System.out.println(disjoint.connected(2,8));
        System.out.println(disjoint.connected(0,8));

    }

}