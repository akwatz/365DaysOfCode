/*
    Given an unweighted undirected graph
    we have to tell if its a tree or not
*/

#include <bits/stdc++.h>

using namespace std;
#define modu 1000000007

class weightedQuickUF{

private:
    vector<int> id;
    vector<int> sz;

public:

    weightedQuickUF(int n){

        id.resize(n);
        sz.resize(n);

        for(int i = 0 ; i < n ; i++)
            id[i] = i , sz[i] = 1;

    }

    int root(int p){

        while(id[p] != p){

            id[p] = id[id[p]];
            p = id[p];

        }

        return p;

    }

    void Union(int p , int q){

        int pRoot = root(p);
        int qRoot = root(q);

        if(sz[pRoot] < sz[qRoot]){

            id[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];

        }

        else{

            id[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];

        }

    }

    bool connected(int p , int q){

        return root(p) == root(q);

    }
    
    bool allConnected(){

        int flag = id[0];

        for(int i = 1 ; i < id.size() ; i++)
            if( id[i] != flag )
                return false;

        return true;
    }

};

int main(){

    int n , m;
    cin>>n>>m;

    weightedQuickUF uf(n);

    while(m--){

        int src , dest;
        
        cin>>src>>dest;

        src-- , dest--;

        if(uf.connected(src , dest)){

            cout<<"NO"<<endl;
            return 0;

        }

        uf.Union(src , dest);

    }

    if( uf.allConnected() )
        cout<<"YES"<<endl;
    else    
        cout<<"NO"<<endl;
    

}