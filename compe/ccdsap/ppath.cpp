#include <bits/stdc++.h>
#include <set>

using namespace std;

bool sieve[10000];

//Function to buils the sieve
void buildSieve()
{

    memset(sieve, true, sizeof(sieve));

    for (int i = 2; i * i <= 10000; i++)
    {

        if (sieve[i])
        {

            for (int p = i * 2; p < 10000; p += i)
                sieve[p] = false;
        }
    }
}

vector<int> prime;

//Function to store all four digit prime numbers
void buildPrime()
{

    for (int i = 1000; i < 9999; i++)
        if (sieve[i])
            prime.push_back(i);
}

vector<int> adj[10000];

//function to add edge between two nodes in a graph
void addEdge(int src, int dest)
{

    //cout<<"src"<<src<<"dest"<<dest<<endl;

    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

//function to tell if two numbers are neighbours or not
bool neighbours(int src, int dest)
{

    string src_string = to_string(src);
    string dest_string = to_string(dest);

    int count = 0;

    for (int i = 0; i < 4; i++)
        if (src_string[i] != dest_string[i])
            count += 1;

    return count == 1;
}

//function to build a graph of prime numbers
void buildGraph()
{

    for (int i = 0; i < prime.size() - 1; i++)
    {
        for (int j = i + 1; j < prime.size(); j++)
        {
            if (neighbours(prime[i], prime[j]))
                addEdge(prime[i], prime[j]);
        }
    }
}

//function to return the cost of reaching dest
//prime number from given source prime number
int cost(int src, int dest)
{

    if(src == dest)
        return 0;
    
    set<int> visited;
    queue<int> q;
    int level = 0;

    q.push(src);
    int n, front, child;

    while (!q.empty())
    {
        //cout << level << endl;

        n = q.size();

        visited.insert(front);
        level += 1;
        while (n--)
        {
            front = q.front();
            q.pop();
            //cout << "chldren of " << front << endl;
            for (int i = 0; i < adj[front].size(); i++)
            {

                child = adj[front][i];
                //cout << child << " ";
                if (child == dest)
                    return level;

                if (visited.find(child) == visited.end())
                {
                    q.push(child);
                    visited.insert(child);
                }
            }
            //cout << endl;
        }
    }

    return -1;
}

int main()
{

    buildSieve();
    buildPrime();
    buildGraph();

    /*for(int i = 0 ; i < prime.size() ; i++){

        int primeNum = prime[i];

        cout<<"Neighbours of "<<primeNum<<endl;

        for(int j = 0 ; j < adj[primeNum].size() ; j++)
            cout<<adj[primeNum][j]<<" ";

        cout<<endl;

    }*/

    int tCase;
    cin >> tCase;

    while (tCase--)
    {

        int src, dest;
        cin >> src >> dest;

        int ans = cost(src, dest);

        if (ans == -1)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}