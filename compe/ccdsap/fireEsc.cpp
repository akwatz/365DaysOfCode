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

        vector<int> roots;
        map<int , int> bag;

        for(int i = 0 ; i < id.size() ; i++)
            if(i == id[i])
                roots.push_back(i);

        for(int i = 0 ; i < id.size() ; i++){

            int rt = root(i);

            if(bag.find(rt) == bag.end())
                bag.emplace(rt , 1);
            else
                bag[rt] += 1;

        }

        cout<<roots.size()<<" ";
        
        long long ans = 1;

        for(auto it = bag.begin() ; it != bag.end() ; it++)
            ans = (ans%modu * it->second%modu)%modu;

        cout<<ans<<endl;

    }

};

int main(){

    int tCase;
    cin>>tCase;

    while(tCase--){

        int N , M;
        cin>>N>>M;

        weightedQuickUF uf(N);

        for(int i = 0 ; i < M ; i++){

            int p , q;
            cin>>p>>q;

            uf.Union(p-1,q-1);

        }

        uf.answer();

    }

}