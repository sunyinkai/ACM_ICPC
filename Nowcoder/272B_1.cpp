#include<cstdio>
#include<vector>
using namespace std;
//树上所有路径的异或和
//f[i]:根到点i的异或和
//转化为给你N<=5e5个数字，求其中任意两个数的异或和．

const int MAXN=5e5+7;
int a[MAXN];
vector<int>G[MAXN];
int f[MAXN];
void dfs(int u,int pre){
	f[u]=f[pre]^a[u];
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(v==pre)continue;
		dfs(v,u);
	}
}

int cnt[32];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<N;++i){
		int x,y;scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	dfs(1,0);

	for(int i=1;i<=N;++i){
		int x=f[i];
		int top=0;
		while(top<31){
			cnt[top]+=x%2;// cnt1的数量
			x/=2;
			++top;
		}
	}

	long long ans=0;
	for(int i=1;i<=N;++i){
		int x=f[i];
		int top=0;
		while(top<31){
			int cnt0=N-cnt[top];
			if(x%2==1){
				ans+=(long long )cnt0*(1<<top);
			}else{
				ans+=(long long )cnt[top]*(1<<top);
			}
			x/=2;
			++top;
		}
	}
	printf("%lld\n",ans/2);
	return 0;
}
