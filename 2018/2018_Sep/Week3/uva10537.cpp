#include<bits/stdc++.h>
using namespace std;
const long long INF=1e10+7;
const int MAXN=256;
int cnt;char s[2],t[2];
long long d[MAXN];
int done[MAXN],pre[MAXN];
vector<int>G[MAXN];
bool isok(long long x){
	int begin=s[0],end=t[0];

	for(int i=0;i<MAXN;++i)d[i]=-INF;
	d[begin]=x;
	memset(done,0,sizeof(done));

	while(true){
		int v=-1;
		for(int u=0;u<MAXN;++u){
			if(!done[u]&&(v==-1||d[u]>d[v]))v=u;
		}
		if(v==-1)break;
		done[v]=true;
		for(int i=0;i<G[v].size();++i){
			int to=G[v][i];
			int cost;
			if(to>='a'&&to<='z')cost=-1;
			else cost=-(d[v]+19)/20;
			if(d[to]<d[v]+cost){
				d[to]=d[v]+cost;
				pre[to]=v;
			}
		}
	}
	return d[end]>=cnt;
}
int tag;
void dfs(int u){
	if(u==t[0]){
		tag=1;
		return;
	}
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		pre[v]=u;
		dfs(v);
		if(tag)return;
	}
}
void findPath(int u){
	if(u==s[0])return;
	findPath(pre[u]);
	printf("-%c",u);
}
int main(){
	int test=1;
	int N;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d",&N)&&(N!=-1)){
		for(int i=0;i<MAXN;++i)G[i].clear();
		memset(pre,0,sizeof(pre));
		for(int i=0;i<N;++i){
			char x[2],y[2];scanf("%s%s",x,y);
			G[(int)x[0]].push_back((int)y[0]);
			G[(int)y[0]].push_back((int)x[0]);
		}
		scanf("%d%s%s",&cnt,s,t);
		printf("Case %d: ",test++);
		long long lo=cnt-1,hi=1e10;
		while(hi-lo>1){
			long long mid=(hi+lo)/2;
			if(isok(mid))hi=mid;
			else lo=mid;
		}
		printf("%lld\n",hi);
	}
	return 0;
}
