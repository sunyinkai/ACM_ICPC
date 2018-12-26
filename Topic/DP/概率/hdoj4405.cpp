#include<cstdio>
#include<cstring>
const int MAXN=2e5+7,MAXM=1e3+7;
double dp[MAXN];
int fly[MAXN];
int main(){
	int N,M;
	while(scanf("%d%d",&N,&M)&&N+M){
		memset(fly,0,sizeof(fly));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			fly[a]=b;
		}
		dp[N]=0;
		for(int i=N-1;i>=0;--i){
			if(fly[i]==0){
				for(int x=1;x<=6;++x){
					dp[i]+=1.0/6*dp[i+x];
				}
				dp[i]++;
			}
			else dp[i]=dp[fly[i]];
		}
		printf("%.4f\n",dp[0]);
	}
	return 0;
}
