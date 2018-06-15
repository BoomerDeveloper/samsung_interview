/*

Link: https://www.geeksforgeeks.org/samsung-delhi-interview-experience-set-27-campus/

Remark : Not Tested

*/


#include <iostream>
using namespace std;
#define INF 1e5

int find(int n, int dist[], int visited[]){
    int pos=-1, val=20001;
    for(int i=1; i<=n; i++){
        if(!visited[i] && dist[i]<val){
            val=dist[i];
            pos=i;
        }
    }
    if(pos!=-1)visited[pos]=1;

    return pos;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;

    while(T--){
        int n;
        cin>>n;

        int arr[n+1][n+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin>>arr[i][j];
            }
        }

        int start;
        cin>>start;

        int dist[n+1];
        for(int i=0;i<n+1; i++)
            dist[i]=INF;
        dist[start]=0;

        int visited[n+1]={0};

        int p=find(n,dist,visited);

        while(p!=-1){
            for(int i=1; i<=n; i++){
                if(arr[p][i]){
                    dist[i]=min(dist[i],dist[p]+arr[p][i]);
                }
            }
            p=find(n,dist,visited);
        }

        int dest;
        cout<< dist[dest] <<endl;

    }

}


