#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const int MAXN=1e4+1;
const int mod=1e9+7;

int ans[MAXN];
int bit[300][MAXN],N;
//bit[i][j]:长度为i;
inline int lowbit(int i){
	return i&-i;
}
int sum(int len,int x){
	int res=0;
	while(x){
		res=(res+bit[len][x])%mod;
		x-=lowbit(x);
	}
	return res;
}

void add(int len,int p,int x){
	x%=mod;
	while(p<=N){
		bit[len][p]=(bit[len][p]+x)%mod;
		p+=lowbit(p);
	}
}

int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		scanf("%d",&N);
		if(N>MAXN){
			printf("%d\n",1/0);
			exit(1);
		}

		for(int i=1;i<=300;++i)
			for(int j=1;j<=N;++j)
				bit[i][j]=0;
		memset(ans,0,sizeof(ans));
		//dp[i][j]:以a[i]结尾的长度为j的个数
		//O(n^2logn) 树状数组优化
		for(int i=1;i<=N;++i){
			int a;
			scanf("%d",&a);
			add(1,a,1);
			for(int j=2;j<=min(300,i);++j){
				int dp=0;
				dp=(dp+sum(j-1,a-1))%mod;//dp[i][j]+=dp[k][j-1];
				ans[j]=(ans[j]+dp)%mod;
				add(j,a,dp);
			}
		}
		ans[1]=N;
		printf("Case #%d:",test);
		for(int i=1;i<=N;++i)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
