#include<bits/stdc++.h>
#include"digraph.hpp"

using namespace std;

digraph::digraph(int V){

    this->V = V;
    adj.resize(V);

}

void digraph::addEdge(int v , int w){

    adj[v].push_back(w);

}

int digraph::getV(){

    return V;

}

void digraph::printGraph(){

    for(int i = 0 ; i < this->V ; i++){

        cout<<i<<" ";

        for(int j = 0 ; j < adj[i].size() ; j++)
            cout<<adj[i][j]<<" ";

        cout<<endl;

    }

}