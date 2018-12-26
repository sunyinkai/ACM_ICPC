#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=257*257;
const int INF=1e9+7;
int p[MAXN];
int a[MAXN];
int dp[MAXN];
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		memset(p,-1,sizeof(p));
		int n,x,y;scanf("%d%d%d",&n,&x,&y);
		for(int i=0;i<x+1;++i)scanf("%d",&a[i]);
		for(int i=0;i<y+1;++i){
			int b;scanf("%d",&b);
			p[b]=i;
		}

		fill(dp,dp+MAXN,INF);
		for(int i=0;i<x+1;++i){
			if(~p[a[i]]){
				int c=p[a[i]];
				*lower_bound(dp,dp+MAXN,c)=c;
			}
		}
		printf("Case %d: %d\n",test,lower_bound(dp,dp+MAXN,INF)-dp);
	}
	return 0;
}
