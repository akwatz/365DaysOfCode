#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[] , int src , int dest){

    adj[src].push_back(dest);
    adj[dest].push_back(src);

}

int farthestNode( int parent , vector<int> adj[] , int n){

    vector<bool> visited(n , false);

     queue<int> q;
     q.push(parent);
     visited[parent] = true;

     int farthest = parent;

     while(!q.empty()){

         farthest = q.front();
         q.pop();

         visited[farthest] = true;

         for(int i = 0 ; i < adj[farthest].size() ; i++)
            if(!visited[ adj[farthest][i] ])
                q.push(adj[farthest][i]);

     }

     return farthest;

}

int longestPath(int parent , vector<int>adj[] , int n){

    vector<bool> visited(n , false);

    queue<int> q;

    q.push(parent);
    visited[parent] = true;

    int level = -1;

    while(!q.empty()){

        int n = q.size();
         
        level += 1;

        while(n--){

            int front = q.front();
            q.pop();

            visited[front] = true;

            for(int i = 0 ; i < adj[front].size() ; i++){

                if( visited[ adj[front][i] ] == false ){     

                    q.push( adj[front][i] );
                }
            }

        }

    }

    return level;

}

int main(){

    int n;
    cin>>n;

    vector<int> adj[n];

    int m = n-1;

    while(m--){

        int src , dest;
        cin>>src>>dest;

        src-- , dest--;

        addEdge(adj , src , dest);

    }

    cout<<longestPath( farthestNode(0 , adj , n) , adj , n )<<endl;

    return 0;

}