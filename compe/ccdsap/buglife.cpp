#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[] , int src , int dest){

    adj[src].push_back(dest);
    adj[dest].push_back(src);

}

int bfs(vector<int> adj[] , int parent , vector<bool> &visited , int gender[]){

    if(visited[parent])
        return 0;

    visited[parent] = true;

    queue<int> q;
    q.push(parent);
    gender[parent] = 0;

    while(!q.empty()){

        int p = q.front();
        q.pop();
        visited[p] = true;

        for(int i = 0 ; i < adj[p].size() ; i++){

            if(visited[ adj[p][i] ]){

                if(gender[p] == gender[ adj[p][i] ])
                    return 1;

            }
            else{

                q.push(adj[p][i]);
                gender[ adj[p][i] ] = !gender[p];

            }

        }
        
    }

    return 0;

}

int main(){

    int tCase;
    cin>>tCase;

    for(int i = 1 ; i <= tCase ; i++){

        int n , m;
        cin>>n>>m;

        vector<int> adj[n];

        for(int j = 0 ; j < m ; j++){

            int src , dest;
            cin>>src>>dest;

            src-- , dest--;

            addEdge(adj , src , dest);

        }

        int flag = 0;

        vector<bool> visited(n , false);
        int gender[n];

        for(int j = 0 ; j < n ; j++){

            flag = bfs(adj , j , visited , gender);

            if(flag == 1)
                break;

        }

        if(flag == 1){

            cout<<"Scenario #"<<i<<":"<<endl;
            cout<<"Suspicious bugs found!"<<endl;

        }

        else{

            cout<<"Scenario #"<<i<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;            

        }

    }

}