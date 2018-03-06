#include<bits/stdc++.h>
using namespace std;

class digraph{

    private:

        int V;

    public:
        digraph(int V);

        vector< vector<int> > adj;
        
        void addEdge(int v , int w);

        int getV();

        void printGraph();


};