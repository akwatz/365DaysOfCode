#include <bits/stdc++.h>
using namespace std;

void addEdge(int src , int dest , vector< pair<int , bool> > adj[] , bool val){

    adj[src].push_back( make_pair(dest , val) );

}

int dfsUtil( vector< pair<int , bool> > adj[] , int parent , vector<bool> &visited , map<int , bool> & bag , bool val ){

    if( visited[parent] ){

        if( bag.find(parent) != bag.end() && bag[parent] != val )
            return 1;

        return 0;

    }

    visited[parent] = true;

    int flag = 0;

    for( int i = 0 ; i < adj[parent].size() ; i++ ){

        flag = flag || dfsUtil( adj , adj[parent][i].first , visited , bag , adj[parent][i].second );

    }

    return flag;

}

int main(){

    map<int , bool> bag;
    int N;
    cin>>N;

    if(N == 0)
        return 0;

    vector< pair<int , bool> > adj[N];
    vector<bool> visited(N , false);
    int flag = 0;

    for( int i = 0 ; i < N ; i++ ){

        int dest;
        string s;

        cin>>dest>>s;

        dest--;

        bool val;

        if(s == "true")
            val = true;

        else 
            val = false;

        if( bag.find(dest) != bag.end() && bag[dest] != val){

            flag = 1;
            break;

        }

        addEdge(i , dest , adj , val);
        bag[dest] = val;

    }

    if(flag == 1){

        cout<<"PARADOX"<<endl;
        return 0;

    }

    for(int i = 0 ; i < N ; i++){

        if(!visited[i])
            flag = flag || dfsUtil(adj , i , visited , bag , true);

    }

    if(flag == 1)
        cout<<"PARADOX"<<endl;

    else
        cout<<"NOT PARADOX"<<endl;

}