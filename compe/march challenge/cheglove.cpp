#include <bits/stdc++.h>
using namespace std;

int main(){

    int tCase;
    cin>>tCase;

    while(tCase--){

        int N;
        cin>>N;

        int finger[N] , glove[N];

        for(int i = 0 ; i < N ; i++)
            cin>>finger[i];

        for(int i = 0 ; i < N ; i++)
            cin>>glove[i];

        int front = 0 , back = 0;

        for( int i = 0 ; i < N ; i++ ){

            if(finger[i] - glove[i] > 0){

                front = 1;
                break;

            }

        }

        for( int i = 0 ; i < N ; i++ ){

            if(finger[i] - glove[N-1-i] > 0){

                back = 1;
                break;

            }

        }

        if( front == 1 && back == 1 )
            cout<<"none"<<endl;
        
        else if(front == 0 && back == 0)
            cout<<"both"<<endl;

        else if(front == 0)
            cout<<"front"<<endl;

        else 
            cout<<"back"<<endl;

    }

    return 0;

}