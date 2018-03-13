import java.util.LinkedList;
import java.util.Queue;

/**
 * Implementation of R way trie
 * Here R is 256 for the processing of all ascii alphabet
 */

 /**
  * RwayTrie
  */
 public class RwayTrie {
 
    private static final int R = 256;

    private static class Node{

        private int value;
        private Node next[] = new Node[R];

    }

    private Node root;

    public void put(String Key , int value){

        root = put(root , Key , value , 0);

    }

    private Node put(Node x , String Key , int value , int d){

        if(x == null)
            x = new Node();

        if(d == Key.length()){

            x.value = value;
            return x;

        }

        char c = Key.charAt(d);
        x.next[c] = put(x.next[c], Key, value, d+1);

        return x;

    }

    public int get(String Key){

        Node add = get(root , Key , 0);

        if(add == null)
            return -1;

        else    
            return add.value;

    }

    private Node get(Node x , String Key , int d){

        if(x == null)
            return null;

        if(d == Key.length())
            return x;

        char c = Key.charAt(d);

        return get(x.next[c] , Key , d + 1);

    }

    public boolean contains(String Key){

        return get(Key) != -1;

    }

    public Iterable<String> keys(){

        Queue<String> queue = new LinkedList<String>();

        collect(root , queue , "" , 0);

        return queue;

    }

    public void collect(Node x , Queue<String> queue , String prefix , int d){

        if(x == null)
            return;

        if(x.value != 0)
            queue.add(prefix);

        for (char c = 0; c < R; c++) {
            collect(x.next[c], queue, prefix + c, d + 1);
        }        

    }

    public static void main(String[] args) {
        
        RwayTrie dictionary = new RwayTrie();

        dictionary.put("hello" , 1);
        dictionary.put("sell", 2);
        dictionary.put("seashore", 3);
        dictionary.put("seashell", 4);
        dictionary.put("shell", 5);
        dictionary.put("shellsort", 6);

        System.out.println(dictionary.contains("shell"));
        System.out.println(dictionary.get("seashell"));
        System.out.println(dictionary.get("hooha"));
        System.out.println(dictionary.get("sea"));

        for (String string : dictionary.keys()) {
            System.out.println(string);
        }

    }

 }