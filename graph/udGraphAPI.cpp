#include<bits/stdc++.h>
#include"udGraphAPI.hpp"
using namespace std;

udGraph::udGraph(int V){

    this->V = V;
    this->adj.resize(V);

}

void udGraph::addEdge(int v , int w){

    this->adj[v].push_back(w);
    this->adj[w].push_back(v);

}

void udGraph::printGraph(){

    for(int i = 0 ; i < this->V ; i++){

        cout<<i<<" ";

        for(int j = 0 ; j < this->adj[i].size() ; j++){

            cout<<this->adj[i][j]<<" ";
        
        }

        cout<<endl;

    }

}

int udGraph::getV(){
    
    return this->V;

}