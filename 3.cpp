#include <stdio.h>
#include <stdlib.h>

int A=7, B=4, G=6;
int visited[8][5];

int h(int x,int y){
    return abs(x-G);   // heuristic
}

int goal(int x,int y){
    return (x==G);
}

void astar(){
    int q[50][3], f=0, r=0;

    q[r][0]=0; q[r][1]=0; q[r][2]=0; r++;   // (x,y,g)

    while(f<r){
        int x=q[f][0], y=q[f][1], g=q[f][2];
        f++;

        if(visited[x][y]) continue;
        visited[x][y]=1;

        printf("(%d,%d)\n",x,y);
        if(goal(x,y)){
            printf("Goal reached!\n");
            return;
        }

        int nx[6]={A,x,0,x,x-(x<B-y?x:B-y),x+(y<A-x?y:A-x)};
        int ny[6]={y,B,y,0,y+(x<B-y?x:B-y),y-(y<A-x?y:A-x)};

        for(int i=0;i<6;i++)
            if(!visited[nx[i]][ny[i]]){
                q[r][0]=nx[i];
                q[r][1]=ny[i];
                q[r][2]=g+1;
                r++;
            }
    }
}

int main(){
    astar();
    return 0;
}
