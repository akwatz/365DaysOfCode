#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

bool sieve[10000];

void buildSieve(){

    memset(sieve , true , sizeof(sieve));

    for(int i = 2 ; i*i <= 10000 ; i++){

        if(sieve[i]){

            for(int p = i*2 ; p < 10000 ; p += i)
                sieve[p] = false;

        }

    }

}

vector<int> prime;

void buildPrime(){

    for(int i = 0 ; i < 9999 ; i++)
        if(sieve[i])
            prime.push_back(i);


}

vector<int> adj[10000];

void addEdge(int src , int dest){

    adj[src].push_back(dest);
    adj[dest].push_back(src);

}

bool neighbours(int src , int dest){
    
    string src_string = to_string(src);
    string dest_string = to_string(dest);

    int count = 0;

    for(int i = 0 ; i < 4 ; i++)
        if(src_string[i] != dest_string[i])
            count += 1;

    return count == 1;

}

void buildGraph(){

    for(int i = 0 ; i < prime.size() - 1; i++){
        for(int j = i + 1 ; j < prime.size() ; j++){
            if(neighbours(prime[i] , prime[j]));
               addEdge(prime[i] , prime[j]);
        }
    }

}

int cost(int src , int dest){

    unordered_set<int> visited;
    queue<int> q;
    int level = 0;

    q.push(src);

    while(!q.empty()){

        int n = q.size();
        level += 1;

        int front = q.front();

        visited.insert(front);

        while(n--){

            for(int i = 0 ; i < adj[front].size() ; i++){

                if(adj[front][i] == dest)
                    return level;

                if( visited.find(adj[front][i]) == visited.end() )
                    q.push(adj[front][i]);

            }

        }

    }

    return -1;

}

int main(){

    buildSieve();
    buildPrime();
    buildGraph();

    int tCase;
    cin>>tCase;

    while(tCase--){

        int src , dest;
        cin>>src>>dest;

        int ans = cost(src , dest);

        if(ans == -1)
            cout<<"Impossible"<<endl;
        else    
            cout<<ans<<endl;
        
    }

    return 0;

}