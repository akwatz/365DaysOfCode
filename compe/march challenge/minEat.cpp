#include <bits/stdc++.h>
using namespace std;

int ans(int l , int r , int arr[] , int n , int H){

    if( l > r )
        return -1;


    int k = ceil( (double)(l + r)/2 );

    if(k == 0)
        return -1;

    int comp = 0;

    for(int i = 0 ; i < n ; i++){

        comp += ceil( (double)arr[i] / k );

    }

    if(comp > H)
        return ans(k + 1 , r , arr , n , H);

    int ans2 = ans( l , k - 1 , arr , n , H );

    if(ans2 == -1)
        return k;

    return ans2;
    
}

int main(){

    int tCase;
    cin>>tCase;

    while(tCase--){

        int N , H;
        cin>>N>>H;

        int arr[N];

        for(int i = 0 ; i < N ; i++)
            cin>>arr[i];

        int maxm = arr[0];

        for(int i = 1 ; i < N ; i++){

            if(arr[i] > maxm)
                maxm = arr[i];

        }

        cout<<ans(0 , maxm , arr , N , H)<<endl;

    }

}