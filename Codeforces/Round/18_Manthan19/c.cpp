#include<cstdio>
const int MAXN=1007;
int a[MAXN][MAXN];
int num=0;
int val[4*4]={
    8,9,1,13,3,12,7,5,0,2,4,11,6,10,15,14
};

void solve(int x,int y,int num){
    int tot=0;
    for(int i=x;i<x+4;i++){
        for(int j=y;j<y+4;j++){
            a[i][j]=val[tot++]+num;
        }
    }
}
int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;i+=4){
        for(int j=0;j<N;j+=4){
            solve(i,j,num);
            num+=16;
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
