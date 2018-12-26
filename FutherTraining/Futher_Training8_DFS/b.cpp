#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=5e4+7;
struct edge{
	int u,v;
};
vector<int>G[MAXN],bcc[MAXN];
int low[MAXN],dfn[MAXN],isCut[MAXN];
int dfs_clock,bcc_cnt,bccno[MAXN];
int N;
stack<edge>S;
void dfs(int ,int );
void find_bcc(){
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(isCut,0,sizeof(isCut));
	memset(bccno,0,sizeof(bccno));
	dfs_clock=bcc_cnt=0;
	while(!S.empty())S.pop();
	for(int i=0;i<=N;++i)bcc[i].clear();
	for(int i=1;i<=N;++i){
		if(!dfn[i])dfs(i,-1);
	}
}

void dfs(int u,int pre){
	dfn[u]=low[u]=++dfs_clock;
	int child=0;
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(v==pre)continue;
		edge e=(edge){u,v};
		if(!dfn[v]){
			S.push(e);
			++child;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				isCut[u]=1;
				bcc_cnt++;
				for(;;){
					edge x=S.top();S.pop();
					if(bccno[x.u]!=bcc_cnt){
						bcc[bcc_cnt].push_back(x.u);
						bccno[x.u]=bcc_cnt;
					}
					if(bccno[x.v]!=bcc_cnt){
						bcc[bcc_cnt].push_back(x.v);
						bccno[x.v]=bcc_cnt;
					}
					if(u==x.u&&v==x.v)break;
				}
			}
		}else{ //if(dfn[v]<dfn[u]){//?
			//S.push(e);
			low[u]=min(low[u],dfn[v]);
		} 
	}
	if(pre==-1&&child==1)isCut[u]=0;
}

int main(){
	int test=1;
	while(~scanf("%d",&N)&&N){
		for(int i=0;i<MAXN;++i)G[i].clear();//这里初始化出了问题
		for(int i=0;i<N;++i){
			int a,b;scanf("%d%d",&a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		find_bcc();
		long long ans0=0,ans2=1;
		for(int i=1;i<=bcc_cnt;++i){
			int len=bcc[i].size();
			int cnt=0;
			for(int j=0;j<len;++j){
				if(isCut[bcc[i][j]])++cnt;
			}
			if(cnt==1){
				++ans0;
				ans2*=(long long)(len-1);
			}
		}
		if(bcc_cnt==1){
			ans0=2;
			ans2=(long long)bcc[1].size()*(bcc[1].size()-1)/2;
		}
		printf("Case %d: %lld %lld\n",test++,ans0,ans2);
	}
	return 0;
}
