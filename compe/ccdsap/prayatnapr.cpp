#include <iostream>
#include <map>
#include <vector>

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
    
    void answer(){

        int ans = 0;
        for(int i = 0 ; i < id.size() ; i++)
            if(i == id[i])
                ans += 1;

        cout<<ans<<endl;

    }

};

int main(){

    int tCase;
    cin>>tCase;

    while(tCase--){

        int n , m;
        cin>>n>>m;

        weightedQuickUF uf(n);

        while(m--){

            int p , q;
            cin>>p>>q;

            uf.Union(p , q);

        }

        uf.answer();

    }

    return 0;

}