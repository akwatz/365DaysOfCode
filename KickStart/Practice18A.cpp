#include<bits/stdc++.h>
using namespace std;

int main(){

    int tCase;
    cin>>tCase;

    int Case = 0;

    while(tCase--){

        Case += 1;

        vector<long long> diffArray(50001 , 0);
        int N;
        cin>>N;

        while(N--){

            int a , b;
            cin>>a>>b;

            diffArray[a-1] += 1;
            diffArray[b] -= 1;

        }

        vector<long long> array(5000 , 0);

        array[0] = diffArray[0];

        for(int i = 1 ; i < 5000 ; i++)
            array[i] = array[i-1] + diffArray[i];

        int P;
        cin>>P;

        cout<<"Case #"<<Case<<":"<<" ";

        while(P--){

            int query;
            cin>>query; 

            cout<<array[query - 1]<<" ";

        }

        cout<<endl;

    }

}