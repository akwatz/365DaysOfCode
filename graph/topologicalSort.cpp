#include <bits/stdc++.h>
#include "digraph.hpp"
using namespace std;

void dfs(digraph G , int parent , vector<bool> &visited , stack<int> &traversal){

    if(visited[parent])
        return;

    visited[parent] = true;

    for(int i = 0 ; i < G.adj[parent].size() ; i++)
        dfs(G , G.adj[parent][i] , visited , traversal);

    traversal.push(parent);

}

void topologicalSort(digraph G){

    vector<bool> visited(G.getV() , false);
    stack<int> traversal;

    for(int i = 0 ; i < G.getV() ; i++){

        if(!visited[i]){

            dfs(G , i , visited , traversal);

        }

    }

    while(!traversal.empty()){

        cout<<traversal.top()<<" ";
        traversal.pop();

    }

    cout<<endl;

}

int main(){

    digraph G(7);
    G.addEdge(0, 2);
    G.addEdge(0, 5);
    G.addEdge(0, 4);
    G.addEdge(6, 0);
    G.addEdge(3, 6);
    G.addEdge(3, 4);
    G.addEdge(3, 5);
    G.addEdge(6, 4);
    G.addEdge(1, 4);

    topologicalSort(G);

}