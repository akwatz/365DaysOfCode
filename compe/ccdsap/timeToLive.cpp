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

    int tCase;
    cin>>tCase;

    while(tCase--){

        int n;
        cin>>n;

        vector<int> adj[n];

        for(int i = 0 ; i < n - 1 ; i++){

            int src , dest;
            cin>>src>>dest;

            addEdge(adj , src , dest);

        }

        int farthest = farthestNode(0 , adj , n);
        //cout<<farthest<<endl;
        int pathLength = longestPath(farthest , adj , n);
        //cout<<pathLength<<endl;
        if(pathLength % 2 == 0)
            cout<<pathLength/2<<endl;

        else
            cout<<(pathLength + 1) / 2<<endl;
        
    }

    return 0;

}