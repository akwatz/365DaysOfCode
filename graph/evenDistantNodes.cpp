#include <bits/stdc++.h>
using namespace std;

long long nck(int n , int k){

    if( k > n )
        return 0;

    if( 2 * k > n )
        k = n - k;

    if(k == 0)
        return 1;

    if(k == 1 || k == n - 1)
        return n;

    long long result = n;

    for(int i = 2 ; i <= k ; i++){

        result *= (n - i + 1);
        result /= i;

    }

    return result;

}

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
    void dfsUtil(int parent , vector<bool> &visited , vector<int> &levels , int level){

        if(visited[parent] == true)
            return;

        levels[level % 2] += 1;
        visited[parent] = true;

        AdjListNode* temp = arr[parent].head;

        while(temp){

            dfsUtil(temp->id , visited , levels , level + 1);
            temp = temp->next;

        }

    }

    int dfs(){

        vector<bool> visited(v , false);

        vector<int> levels(2 , 0);

        dfsUtil(0 , visited , levels , 0);

        return (nck(levels[0] , 2) + nck(levels[1] , 2));

    }

};

int main(){

    int tCase;
    cin>>tCase;
    
    while(tCase--){
        
        int v;
        cin>>v;
        
        Graph graph(v);
        
        for(int i = 0 ; i < v - 1; i++){
            
            int src , dest;
            cin>>src>>dest;
            
            graph.addEdge(src - 1 , dest - 1);
            
        }

        cout<<graph.dfs()<<endl;
        
    }


}

