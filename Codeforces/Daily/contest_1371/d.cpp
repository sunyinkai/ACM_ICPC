#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=307;
int a[MAXN][MAXN];

void paint(int N,int K){
    memset(a,0,sizeof(a));
    int nx=0,ny=0;
    while(K--){
        a[nx][ny]=1;
        nx++;
        ny++;
        if(nx==N){
            nx%=N;
            ny++;
        }
        ny%=N;
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int N,K;scanf("%d%d",&N,&K);
        paint(N,K);
        int MAXR=-1,MAXC=-1;
        int MINR=2*K,MINC=2*K;
        for(int i=0;i<N;++i){
            int R=0,C=0;
            for(int j=0;j<N;++j){
                R+=a[i][j];
                C+=a[j][i];
            }
            MAXR=max(MAXR,R);
            MINR=min(MINR,R);
            MAXC=max(MAXC,C);
            MINC=min(MINC,C);
        }
        printf("%d\n",(MAXR-MINR)*(MAXR-MINR)+(MAXC-MINC)*(MAXC-MINC));
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
