#include <bits/stdc++.h>
using namespace std;

//Defining class graph
class graph{

public:

    int V;              //number of nodes in the graph
    vector< vector<int> > mat;          //relation between the nodes

    //constructor
    graph(int v){

        V = v;
        
        //allocating memory to adjacency matrix
        for(int i = 0 ; i < v ; i++){

            vector<int> temp(v , 0);

            mat.push_back(temp);

        }


    }

    //functionn to add edge between nodes
    void addEdge(int src ,int dest){

        mat[src][dest] = 1;
        mat[dest][src] = 1;

    }

    //utitlity function to carry out dfs
    void dfsUtil(int parent , vector<bool> &visited){

        if(visited[parent] == true)     //if node is visited then return
            return;

        cout<<parent<<" ";              //visit the node

        visited[parent] = true;         //mark it visited

        //visit the children
        for( int i = 0 ; i < V ; i++ )
            if(mat[parent][i] == 1)
                dfsUtil(i , visited);

    }

    //function to call out utility function to carry dfs
    void dfs(){

        vector<bool> visited(V , false);

        dfsUtil(0 , visited);

    }  

    //function to do bfs
    void bfs(){

        vector<bool> visited(V , false);        //keep track of visited nodes
        queue<int> BfsQueue;

        BfsQueue.push(0);

        while(BfsQueue.empty() == false){

            int parent = BfsQueue.front();      //pop the front node
            BfsQueue.pop();

            if(visited[parent] == true)         //if the node is visited then continue
                continue;

            cout<<parent<<" ";                  //visit the node

            visited[parent] = true;             //mark it visited

            //enqueue the children
            for(int i = 0 ; i < V ; i++)
                if(mat[parent][i] == 1)
                    BfsQueue.push(i);    

        }


    } 

};

int main(){

    graph demo(7);

    demo.addEdge(0 , 1);
    demo.addEdge(0 , 2);
    demo.addEdge(0 , 4);
    demo.addEdge(4 , 5);
    demo.addEdge(5 , 2);
    demo.addEdge(2 , 3);
    demo.addEdge(2 , 6);

    demo.dfs();

    cout<<endl;

    demo.bfs();

    return 0;

}