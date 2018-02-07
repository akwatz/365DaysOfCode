#include <bits/stdc++.h>
using namespace std;

//structure of adjacency list node
struct AdjListNode{

    int id;
    AdjListNode* next;

};

//struture of adjacency list
struct AdjList{

    AdjListNode* head;

};

//Function to create new node
AdjListNode* newNode(int id){

    AdjListNode* tempNode = new AdjListNode;
    tempNode->id = id;
    tempNode->next = NULL;

    return tempNode;

}


//structure of graph
class Graph{

public:
    int v;                      //number of edges
    vector<AdjList> arr;        //array of adjacency lists

    Graph(int V){

        v = V;
        arr.resize(v);

        for(int i = 0 ; i < v ; i++)
            arr[i].head = NULL;

    }

    //Function to add edge to the graph
    void addEdge( int src , int dest){

        //creating source and destination nodes
        AdjListNode* srcNode = newNode(src);
        AdjListNode* destNode = newNode(dest);

        //Pushing source node to destination node
        srcNode->next = arr[dest].head;
        arr[dest].head = srcNode;

        //Pushing destination node to source node
        destNode->next = arr[src].head;
        arr[src].head = destNode;

    }

    //Function to print the adjacency list
    void print(){

        for(int i = 0 ; i < v ; i++){

            cout<<i;

            AdjListNode* traveller = arr[i].head;

            while(traveller){

                cout<<"->"<<traveller->id;
                traveller = traveller->next;

            }

            cout<<endl;

        }

    }

    //Function to do BFS 
    void bfs(){

        cout<<"BFS of the graph"<<endl;

        //creating queue to store the children of the nodes
        queue<int> bfsQueue;
        vector<bool> visited(v , false);        //to keep track of the visited nodes

        bfsQueue.push(0);

        while(!bfsQueue.empty()){

            int traveller = bfsQueue.front();
            bfsQueue.pop();

            if(visited[traveller] == true)      //mark visited
                continue;

            cout<<traveller<<" ";

            visited[traveller] = true;

            AdjListNode* temp = arr[traveller].head;

            //Enqueue all the children of the node
            while(temp){

                bfsQueue.push(temp->id);
                temp = temp->next;

            }

        }

    }

    //Utility function for the dfs of the graph
    void dfsUtil(int parent , vector<bool> &visited){

        if(visited[parent] == true)
            return;

        cout<<parent<<" ";
        visited[parent] = true;

        AdjListNode* temp = arr[parent].head;

        while(temp){

            dfsUtil(temp->id , visited);
            temp = temp->next;

        }

    }

    void dfs(){

        cout<<"DFS of the graph"<<endl;

        vector<bool> visited(v , false);

        dfsUtil(0 , visited);

    }

};


int main(){

    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge( 0, 4);
    graph.addEdge( 1, 2);
    graph.addEdge( 1, 3);
    graph.addEdge( 1, 4);
    graph.addEdge( 2, 3);
    graph.addEdge( 3, 4);
    // print the adjacency list representation of the above graph
    graph.print();

    graph.bfs();

    graph.dfs();

    return 0;

}

