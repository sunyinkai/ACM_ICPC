#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=5e5+7;

int a[MAXN],size[MAXN],N;
vector<int>G[MAXN];
long long ans=0;
void dfs(int u,int pre){
	size[u]=1;
	vector<int>t;
	int len=G[u].size();
	if(len==1)t.push_back(0);
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(v==pre)continue;
		dfs(v,u);
		size[u]+=size[v];
		t.push_back(size[v]);
	}
	t.push_back(N-size[u]);

	//求N个数两两相乘的结果
	int len2=t.size();
	long long tmp=0;
	int all=N-1;
	for(int i=0;i<len2;++i){
		all-=t[i];
		tmp+=(long long)all*t[i];
	}
	tmp+=N-1;
	if(tmp&1)ans^=a[u];
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<N;++i){
		int x,y;scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
