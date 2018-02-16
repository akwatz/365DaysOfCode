#include <bits/stdc++.h>
using namespace std;

//Function to add edge between the nodes of the graphs
void addEdge(vector<int> adj[] , int u , int v){

    adj[u].push_back(v);
    adj[v].push_back(u);

}

//Utility function to carry out dfs
void dfsUtil(vector<int>adj[] , int parent , vector<bool> &visited){

    //check if node is visited
    if(visited[parent] == true)
        return;

    visited[parent] = true;     //mark it visited
    cout<<parent<<"\t";

    //visit all its children
    for(int i = 0 ; i < adj[parent].size() ; i++)
        dfsUtil(adj , adj[parent][i] , visited);

}

//Function to do dfs of the graph
void DFS(vector<int> adj[] , int V){

    vector<bool> visited(V , false);

    for(int i = 0 ; i < V ; i++)
        dfsUtil(adj , i , visited);

}

int main(){

    int V = 5;                  //Number of nodes
    vector<int> adj[V];         //Adjacency list of the nodes

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    DFS(adj, V);

    return 0;

}