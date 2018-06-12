/*

Question: https://www.geeksforgeeks.org/samsung-interview-experience-r-d-noida-off-campus/

Input :

1
1 1 6 4
2
2 2 5 3 1
3 2 6 3 10

Methodology:
Trying out all the possible combinations of edges.

*/

#include <iostream>
using namespace std;\

struct Edge{
    int sx,sy,dx,dy,w;

    Edge(){}

    Edge(int a, int b, int c, int d, int e){
        sx=a, sy=b, dx=c, dy=d, w=e;
    }
};

int abs(int n){
    return (n<0)?(-1*n):n;
}

bool is_on(int comb, int idx){
    return (comb>>idx)&1;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;

    while(T--){

        int Sx,Sy;
        int Dx,Dy;

        cin>>Sx>>Sy;
        cin>>Dx>>Dy;

        int N;
        cin>>N;

        int sx,sy;
        int dx,dy;
        int w;

        Edge edges[2*N];

        for(int i=0; i<2*N; i+=2){

            cin>>sx>>sy;
            cin>>dx>>dy;
            cin>>w;

            Edge* worm_hole_pos = new Edge(sx,sy,dx,dy,w);
            Edge* worm_hole_neg = new Edge(dx,dy,sx,sy,w);

            edges[i]   = *worm_hole_pos;
            edges[i+1] = *worm_hole_neg;
        }

        // the possible catch would be N<=10;
        // assuming that wormholes are in correct order s->d and not d->s
        // also assuming that the worm holes where sorted based on start

        int total_combinations = ((1<<N)-1);
        int min_dist=abs(Sx-Dx)+abs(Sy-Dy);

        for(int comb=0; comb<=total_combinations; comb++){

            bool is_first=true;
            Edge prev;
            int dist=0;

            for(int idx=0; idx<N; idx++){
                if( is_on(comb,idx) ){

                    if(is_first){
                       dist+= (abs(Sx - edges[idx].sx) + abs(Sy - edges[idx].sy));
                       dist+= edges[idx].w;
                       prev = edges[idx];
                       is_first=false;
                    }else{
                        dist+= (abs(prev.dx - edges[idx].sx) + abs(prev.dy - edges[idx].sy));
                        dist+= edges[idx].w;
                        prev = edges[idx];
                    }

                }
            }


            dist+= (abs(prev.dx - Dx) + abs(prev.dy - Dy));
            min_dist=min(dist,min_dist);

        }

         cout<<min_dist<<endl;

    }

    return 0;
}
