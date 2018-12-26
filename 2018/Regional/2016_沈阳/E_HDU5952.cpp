#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXE=1007;
const int MAXN=107;
const int MAXV=107;
vector<int>G[MAXN];
int has[MAXN][MAXN];
int ans,du[MAXN],len[MAXN];
int N,M,S,q[MAXN];
inline bool check(int now,int top){
	for(int i=0;i<=top;++i){
		if(!has[q[i]][now])return false;
	}
	return true;
}
//只选择比当前点大的点
//如果度数小于S-1直接不考虑
//起点的最大坐标N-S+1
//将G[i]:里的点排序
void dfs(int u,int pre,int top){
	if(top==S-1){
		++ans;
		return ;
	}
	q[top]=u;
	for(int i=0;i<len[u];i++){//将i=0改为i=top
		int v=G[u][i];
		if(v==pre)continue;
		if(du[v]<S-1)continue;//度数不够
		if(v>u){
			if(check(v,top)){//O(top)
				dfs(v,u,top+1);
			}
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&N,&M,&S);
		for(int i=1;i<=N;++i)du[i]=0,G[i].clear(),len[i]=0;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				has[i][j]=0;
		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			du[a]++;du[b]++;
			len[a]++;len[b]++;
			G[a].push_back(b);
			G[b].push_back(a);
			has[a][b]=has[b][a]=1;
		}
		ans=0;
		for(int i=1;i<=N-S+1;++i){
			sort(G[i].begin(),G[i].end());
			if(du[i]<S-1)continue;
			dfs(i,-1,0);
		//	printf("----------\n");
		}
		printf("%d\n",ans);
	}
	return 0;
}
