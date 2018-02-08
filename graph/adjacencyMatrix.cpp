#include <iostream>
#include <vector>
using namespace std;

class graph{

public:

    int V;
    vector< vector<int> > mat;

    graph(int v){

        V = v;
        
        for(int i = 0 ; i < v ; i++){

            vector<int> temp(v , 0);

            mat.push_back(temp);

        }


    }

    void addEdge(int src ,int dest){

        mat[src][dest] = 1;
        mat[dest][src] = 1;

    }

    void dfsUtil(int parent , vector<bool> &visited){

        if(visited[parent] == true)
            return;

        cout<<parent<<" ";

        visited[parent] = true;

        for( int i = 0 ; i < V ; i++ )
            if(mat[parent][i] == 1)
                dfsUtil(i , visited);

    }

    void dfs(){

        vector<bool> visited(V , false);

        dfsUtil(0 , visited);

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

    return 0;

}