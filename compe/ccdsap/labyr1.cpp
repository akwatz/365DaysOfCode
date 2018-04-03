#include <bits/stdc++.h>

typedef long long  ll;

#define MOD               1000000007
#define scll(t)               scanf("%lld",&t)
#define sc(t)                 scanf("%d",&t)
#define max(a,b)         (a>=b?a:b)
#define min(a,b)          (a<b?a:b)
#define gc                    getchar_unlocked
#define mp                   make_pair
#define pb                    push_back
#define Size(a)            int((a).size())
#define F                     first
#define S                     second

using namespace std;

char grid[10001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int C , R , len;
int dr[] = {0 , 0 , 1 , -1};
int dc[] = {1 , -1 , 0 , 0};
pair<int , int> diameterEnd;

bool inGrid(pair<int , int> st){

    if(st.F >= 0 && st.F < R && st.S >= 0 && st.S < C)
        return true;

    return false;

}

void bfs( pair<int , int> st ){

    queue< pair<int , int> > q;

    q.push(st);
    visited[st.F][st.S] = true;

    while( !q.empty() ){

        pair<int , int> curr = q.front() , next;

        q.pop();

        for( int i = 0 ; i < 4 ; i++ ){

            next.F = curr.F + dr[i];
            next.S = curr.S + dc[i];

            if( inGrid(next) && grid[next.F][next.S] == '.' && !visited[next.F][next.S] ){

                visited[next.F][next.S] = true;
                q.push(next);

                dist[next.F][next.S] = dist[curr.F][curr.S] + 1;

                if( dist[next.F][next.S] > len ){
                    len = dist[next.F][next.S];
                    diameterEnd.F = next.F;
                    diameterEnd.S = next.S;
                }
            }


        }

    }

}

int main(){

    int tCase;
    cin>>tCase;

    while(tCase--){

        cin>>C>>R;

        memset(grid , 0 , sizeof(grid));
        memset(visited , false , sizeof(visited));
        memset(dist , 0 , sizeof(dist));
        len = 0;

        for(int i = 0 ; i < R ; i++)
            cin>>grid[i];

        int present = 0;
        pair<int , int> st;

        for(int i = 0 ; i < R ; i++){

            for(int j = 0 ; j < C ; j++){

                    if(grid[i][j] == '.'){
                        st = mp(i , j);
                        present = 1;
                        break;
                    }
            }

            if(present)
                break;

        }

        bfs(st);

        memset(visited , false , sizeof(visited));
        memset(dist , 0 , sizeof(dist));

        len = 0;

        bfs(diameterEnd);

        cout<<"Maximum rope length is "<<len<<"."<<endl;


    }

    return 0;

}