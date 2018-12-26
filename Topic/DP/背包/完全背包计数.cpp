#include<cstdio>
const int MAXN=1e5+7;
const int INF=1e5;
int V[25];
int Maxtot=2;
int tot=0;
int cnt[25];
long long res=0;
long long mod=1e9+7;
void  dfs(long long N,int kind){
	if(N==0){
		long long t=0;
		for(int i=0;i<tot;++i){
	//		printf("%d ",cnt[i]);
			t+=cnt[i]*(i+1)*(i+1);
		}
	//	printf("\n");
		res=res+t*t;
		return;
	}
	if(kind<0)return;
		for(int k=N/V[kind];k>=0;--k){
			if(N>=k*V[kind]){
				cnt[kind]=k;
				dfs(N-k*V[kind],kind-1);
				cnt[kind]=0;
			}
		}
}
int main(){
	int i=1,j=2;
	V[0]=1;V[1]=2;
	while(1){
		int t=j;
		j=i+j;
		i=t;
		if(j>=INF)break;
		V[Maxtot++]=j;
	}
	for(int N=1;N<=100;++N){
		printf("N=%d\n",N);
		//int N;scanf("%d",&N);
		for(tot=0;V[tot]<=N;++tot);
		//printf("V[tot]=%d\n",V[tot]);
		dfs(N,tot-1);
		printf("%lld\n",res);
	}


	/*int dp[MAXN];
	dp[0]=1;
	for(int i=0;i<Maxtot;++i){
		for(int j=V[i];j<MAXN;++j){
			if(j>=V[i])dp[j]+=dp[j-V[i]];
		}
	}
	printf("dp[4]=%d\n",dp[4]);
	printf("%d\n",dp[INF]);
	*/
	return 0;
}
