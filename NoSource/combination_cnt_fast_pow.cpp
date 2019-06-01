//矩阵快速幂, 0<=x_i<=b
#include<cstdio>
const int MAXM=107;
const long long mod=1e9+7;
long long M,B,N;

struct matrix{
    long long a[MAXM][MAXM];
}base,ans;

matrix multi(const matrix& x,const matrix& y){
    matrix ans;
    for(int i=0;i<=M;++i){
        for(int j=0;j<=M;++j){
            ans.a[i][j]=0;
            for(int k=0;k<=M;++k){
                ans.a[i][j]+=x.a[i][k]*y.a[k][j];
            }
            ans.a[i][j]%=mod;
        }
    }
    return ans;
}

matrix fast_pow(long long N){
    //build ans;
    for(int i=0;i<=M;++i){
        for(int j=0;j<=M;++j){
            ans.a[i][j]=(i==j?1:0);
        }
    }
    //build base;
    for(int i=0;i<=M;++i){
        for(int j=0;j<=M;++j){
            if(i>j){base.a[i][j]=0;}
            else base.a[i][j]=(i+B>=j?1:0);
            printf("%lld ",base.a[i][j]);
        }
        printf("\n");
    }


    while(N){
        if(N&1)ans=multi(ans,base);
        base=multi(base,base);
        N/=2;
    }
    return ans;
}

int main(){
    scanf("%lld%lld%lld",&M,&B,&N);
    matrix res=fast_pow(N);
    printf("%lld\n",res.a[0][M]);
    return 0;
}
