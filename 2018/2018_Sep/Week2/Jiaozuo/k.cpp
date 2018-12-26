#include<cstdio>
#include<cstring>
const int MAXN=500;
const long long mod=1e9+7;
long long dp[MAXN][10007];
int cnt;
int power[21];
void init(){
	long long val=1;
	for(int i=0;i<=20;++i){
		power[i]=val-1;
		val=val*2;
	}
}

int weight[MAXN];
int main(){
	int T;scanf("%d",&T);
	init();
	while(T--){
		cnt=0;
		int N,Q;scanf("%d%d",&N,&Q);
		for(int i=0;i<N;++i){
			int V,C;
			scanf("%d%d",&V,&C);

			C=power[C];
			for(int k=1;k<=C;k*=2){
				weight[cnt]=k*V;
				++cnt;
				C-=k;
			}
			if(C>0){
				weight[cnt]=C*V;
				++cnt;
			}
		}
		/*for(int i=0;i<cnt;++i){
			printf("weight[%d]=%d,val[%d]=%d\n",i,weight[i],i,val[i]);
		}*/
		for(int i=0;i<=cnt;++i)
			for(int j=0;j<=10000;++j)dp[i][j]=0;
		dp[0][0]=1;
		for(int i=0;i<cnt;++i){
			for(int j=10000;j>=0;--j){
				if(j>=weight[i])dp[i+1][j]=(dp[i+1][j]+dp[i][j-weight[i]])%mod;
				dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
			}
		}
		while(Q--){
			int S;scanf("%d",&S);
			printf("%lld\n",dp[cnt][S]);
		}
	}
	return 0;
}
