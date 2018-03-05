/*This programm implements the weighted quick union
find data structure with path compression technique.*/

import java.io.*;
import java.util.*;

/**
 * weightedQuickUF
 */
public class weightedQuickUF {

   private int[] id;
   private int[] sz;

   public weightedQuickUF(int N){

       id = new int[N];
       sz = new int[N];

       for (int i : id) {

           id[i] = i;
           sz[i] = 1;
           
       }

   }

   private int root(int i) {

       while(i != id[i]){

           id[i] = id[id[i]];

           i = id[i];

       }

       return i;
       
   } 

   public boolean connected(int p , int q) {

        return root(p) == root(q);
       
   }

   public void union(int p , int q) {

       int pid = root(p);
       int qid = root(q);

       if(sz[pid] < sz[qid]){

           id[pid] = qid;
            sz[qid] += sz[pid];

       }

       else{

           id[qid] = pid;
           sz[pid] += sz[qid];

       }
       
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