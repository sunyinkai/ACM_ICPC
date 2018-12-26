#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=22;
long long dp[1<<MAXN],visit[1<<MAXN];
long long a[MAXN],b[MAXN];
vector<int>G[MAXN];
long long len[MAXN];
long long res=0;
int N;
long long dfs(int S){//init S=0
	if(visit[S])return dp[S];
	dp[S]=0;
	visit[S]=1;
	int cnt=__builtin_popcount(S);
	long long res=0;
	for(int i=0;i<N;++i){
		if(!(S&(1<<i))){//i点没访问过
			int x=i+1;//考虑i点
			//判断能不能转移
			bool isok=true;
			for(int j=0;j<len[x];++j){
				if(S&(1<<(G[x][j]-1)));
				else isok=false;
			}
			if(isok){
				res=max(res,dfs(S|(1<<i))+a[x]*(cnt+1)+b[x]);
			}
		}
	}
	return dp[S]=res;
}

int done[MAXN];
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		scanf("%lld%lld%lld",&a[i],&b[i],&len[i]);
		memset(done,0,sizeof(done));
		for(int j=0;j<len[i];++j){
			int x;scanf("%d",&x);
			G[i].push_back(x);//重边
		}
	}
	printf("%lld\n",dfs(0));
	return 0;
}
