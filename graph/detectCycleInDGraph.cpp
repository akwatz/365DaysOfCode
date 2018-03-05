#include <iostream>
using namespace std;

void addEdge(vector<int> adj[] , int u , int v){

    adj[u].push_back(v);

}

void dfs