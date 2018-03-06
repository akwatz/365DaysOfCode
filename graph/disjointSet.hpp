#include <bits/stdc++.h>
using namespace std;

class disjointSet{

public:

    vector<int> id;
    vector<int> sz;

    disjointSet(int n);

    int find(int child);

    bool isConnected(int v , int w);

    void merge(int v , int w);

};