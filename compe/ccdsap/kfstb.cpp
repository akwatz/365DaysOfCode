#include <bits/stdc++.h>
using namespace std;

#define modu 1000000007

void addEdge(vector<int> adj[] , int src , int dest){

    adj[src].push_back(dest);

}

long long findPath( vector<int> adj[] , int parent , vector<long long> &path , vector<bool> &visited ){

    if(path[parent] != 0)
        return path[parent];

    if(visited[parent])
        return 0;

    visited[parent] = true;

    for( int i = 0 ; i < adj[parent].size() ; i++ ){

        path[parent] = ( path[parent] + findPath(adj , adj[parent][i] , path , visited) ) % modu;

    }

    return path[parent];

}


long long answer( vector<int> adj[] , int n , int s , int t ){

    vector<long long> path(n , 0);
    vector<bool> visited(n , 0);

    path[t] = 1;

    return findPath(adj , s , path , visited);

}

int main(){

    int tCase;
    cin>>tCase;

    while(tCase--){

        int c , b , s , t;
        cin>>c>>b>>s>>t;

        vector<int> adj[c];

        s-- , t--;

        while(b--){

            int src , dest;
            cin>>src>>dest;

            src-- , dest--;

            addEdge(adj , src , dest);

        }

        cout<<answer(adj , c , s , t)<<endl;

    }

    return 0;

}