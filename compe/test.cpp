#include <bits/stdc++.h>
using namespace std;

int main(){

    set<int> s;

    s.insert(5);
    s.insert(-1);
    s.insert(7);
    s.insert(-7);

    for(set<int>::iterator it = s.begin() ; it != s.end() ; it++)
        cout<<*it<<endl;

    return 0;

}