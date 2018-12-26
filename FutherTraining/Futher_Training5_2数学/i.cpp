#include<cstdio>
#include<cstring>
#define eps 1e-9;
const int MAXN=1e6+7;
double dp[MAXN];
int isPrime[MAXN];
int prime[MAXN],top=0;
void init(){
	memset(isPrime,-1,sizeof(isPrime));
	isPrime[1]=0;
	for(int i=2;i<MAXN;++i){
		if(isPrime[i]){
			prime[top++]=i;
			for(int j=2*i;j<MAXN;j+=i)isPrime[j]=0;
		}
	}
}
double dfs(int x){
	if(x==1)return 0.0;
	if(dp[x])return dp[x];
	int a[500],tot=0,cnt=0;
	for(int k=0;prime[k]<=x&&k<top;++k){
		++cnt;
		if(x%prime[k]==0){
			a[tot++]=prime[k];
		}
	}
	double val=0.0;
	for(int i=0;i<tot;++i)
		if(a[i]!=x)val+=dfs(x/a[i])*1.0/tot;
	val+=cnt*1.0/tot;
	return dp[x]=val;
}
int main(){
	init();
	int T;scanf("%d",&T);
	dp[1]=0.0;
	for(int test=1;test<=T;++test){
		int N;scanf("%d",&N);
		printf("Case %d: %.6f\n",test,dfs(N));
	}
	return 0;
}
