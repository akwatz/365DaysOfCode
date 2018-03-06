#include<bits/stdc++.h>
using namespace std;

class udGraph{

public:
    int V;
    vector< vector<int> > adj;

    udGraph(int n);
    void addEdge(int v , int w);
    void printGraph();

};