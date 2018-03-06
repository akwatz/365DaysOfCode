#include <bits/stdc++.h>
#include "disjointSet.hpp"

using namespace std;

disjointSet::disjointSet(int n){

    id.resize(n);
    sz.resize(n);

    for (int i = 0; i < n; i++)
    {

        id[i] = i;
        sz[i] = 1;
    }
}

int disjointSet::find(int child){

    while(id[child] != child){

        id[child] = id[id[child]];

        child = id[child];

    }

    return child;

}

bool disjointSet::isConnected(int v , int w){

    return id[v] == id[w];

}

void disjointSet::merge(int p , int q){

    int pid = find(p);
    int qid = find(q);

    if(sz[pid] < sz[qid]){

        id[pid] = qid;
        sz[qid] += sz[pid];

    }

    else{

        id[qid] = pid;
        sz[pid] += sz[qid];
    
    }

}