#include <bits/stdc++.h>
#include <map>
using namespace std;

class Graph{

public:
    int V;
    vector< vector<int> > adj;
    int count;
    vector<int> Indegree;
    map<string , int> sti;
    map<int , string> its;

    Graph(int v){

        this->V = v;
        adj.resize(v);
        this->Indegree.resize(v);
        for(int i = 0 ; i < v ; i++)
            Indegree[i] = 0;

        count = 0;

    }

    string getString(int vertex){

        return its[vertex];

    }

    int getInt(string vertex){

        return sti[vertex];

    }

    void addEdge(string src , string dest){

        if(sti.find(src) == sti.end()){

            sti[src] = count;
            its[count++] = src;

        }

        if(sti.find(dest) == sti.end()){

            sti[dest] = count;
            its[count++] = dest;

        }

        adj[ sti[src] ].push_back( sti[dest] );
        Indegree[ sti[dest] ] += 1;

    }

    void print(){

        int index = 0;

        for(int i = 0 ; i < this->V ; i++)
            if(Indegree[i] == 0){
                
                index = i;
                break;

            }

        for(int i = 0 ; i < this->V - 1 ; i++){

            cout<<this->getString(index)<<"-";

            index = this->adj[index][0];

            cout<<this->getString(index)<<" ";

        }

    }

};

int main(){

    int tCase;
    cin>>tCase;

    for(int kase = 1 ; kase <= tCase ; kase++){

        int V;
        cin>>V;

        Graph G(V+1);

        for(int i = 0 ; i < V ; i++){

            string src = "", dest = "";
            cin>>src>>dest;

            G.addEdge(src , dest);

        }

        cout<<"Case #"<<kase<<":"<<" ";
        G.print();
        cout<<endl;

    }

}