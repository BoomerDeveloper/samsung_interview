/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/

*/

#include <iostream>
using namespace std;

bool visited[1000];
int adj_matrix[1000][1000];

int max_prob=0;
int max_prob_idx;
int N;

void dfs(int time, int idx, int prob){


    if(time<=10){
        if(prob>max_prob){
            max_prob = max(max_prob, prob);
            max_prob_idx = idx;
        }
        return ;
    }

    visited[idx]=true;

    for(int i=0; i<N; i++){
        if( adj_matrix[idx][i] && !visited[i] ){
            dfs(time-10, i, prob*(adj_matrix[idx][i]) );
        }
    }

    visited[idx]=false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;

    while(T--){

        for(int i=0;i<1000;i++)
            visited[i]=false;

        cin>>N;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                adj_matrix[i][j]=0; // probability is zero
            }
        }


        int E;
        cin>>E;

        int x,y,prob;
        while(E--){
            cin>>x>>y>>prob;
            adj_matrix[x-1][y-1]=prob;
        }

        int time;
        cin>>time;

        dfs(time,0,1);

        cout<<max_prob_idx<<endl;
    }

}
