//tag: matrix_fast_pow
#include<cstdio>
const int MAXN=107;
const long long mod=1e9+7;
struct matrix{
    long long a[MAXN][MAXN];
};

int N;long long M;
matrix multi(matrix x,matrix y){
    matrix t;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            t.a[i][j]=0;
            for(int k=0;k<N;++k){
                t.a[i][j]+=x.a[i][k]*y.a[k][j]%mod;
            }
            t.a[i][j]%=mod;
        }
    }   
    return t;
}

matrix fast_pow(matrix base,long long M){
    matrix res;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            res.a[i][j]=(i==j?1:0);
    while(M){
        if(M&1)res=multi(res,base);
        base=multi(base,base);
        M/=2;
    }
    return res;
}

int main(){
    scanf("%d%lld",&N,&M);   
    matrix base;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            scanf("%lld",&base.a[i][j]);
        }
    }
    matrix res=fast_pow(base,M);
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)
            printf("%lld ",res.a[i][j]);
        printf("\n");
    }
    return 0;
}
