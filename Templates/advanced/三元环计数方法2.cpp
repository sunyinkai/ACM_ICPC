//hdoj6184
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e5+7;
vector<int>G[MAXN];
set<LL>st;
int du[MAXN],par[MAXN],visit[MAXN];
int main(){
	//int T;scanf("%d",&T);
	int N,M;
	while(~scanf("%d%d",&N,&M)){
		//int N,M;scanf("%d%d",&N,&M);
		st.clear();
		memset(du,0,sizeof(du));
		memset(visit,0,sizeof(visit));
		memset(par,0,sizeof(par));
		for(int i=0;i<=N;++i)G[i].clear();

		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
			du[a]++;du[b]++;
			st.insert((LL)a*N+b);
			st.insert((LL)b*N+a);
		}
		int limit=sqrt(M);
		long long res=0;
		for(int u=1;u<=N;++u){
			visit[u]=1;
			for(auto v:G[u])par[v]=u;
			for(auto v:G[u]){
				int cnt=0;
				if(visit[v])continue;
				if(du[v]<=limit){
					for(auto vv:G[v])if(par[vv]==u)++cnt;
				}else{
					for(auto vv:G[u])if(st.find((LL)v*N+vv)!=st.end())++cnt;
				}
				res+=(LL)cnt*(cnt-1)/2;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
