#include <bits/stdc++.h>
using namespace std;

int main(){

    int tCase;
    cin>>tCase;

    while(tCase--){

        int N , H;
        cin>>N>>H;

        int arr[N];

        for(int i = 0 ; i < N ; i++)
            cin>>arr[i];

        sort(arr , arr + N);

        if(H-N == 0)
            cout<<arr[N-1]<<endl;

        else{

            int bareMin = arr[N-1-(H-N)];

            cout<<max(bareMin , arr[N-1]-bareMin)<<endl;

        }

    }

    return 0;

}