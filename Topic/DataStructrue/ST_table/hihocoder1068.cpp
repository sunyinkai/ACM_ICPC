#include<cstdio>
#define min(a,b) (a<b?a:b)
const int MAXN=1e6+7;
int f[MAXN][21];
int RMQ(int l,int r){
    int k=0;
    while(1<<(k+1)<=r-l+1)++k;
    return min(f[l][k],f[r-(1<<k)+1][k]);
}

int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i)
        scanf("%d",&f[i][0]);
    for(int k=1;(1<<k)<=N;++k)
        for(int i=1;i+(1<<k)-1<=N;++i)
            f[i][k]=min(f[i][k-1],f[i+(1<<(k-1))][k-1]);
    int M;scanf("%d",&M);
    while(M--){
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",RMQ(l,r));
    }
    return 0;
}
