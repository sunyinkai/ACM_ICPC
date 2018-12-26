#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+7;

struct node{
	int x,w;
	int id;
	int val;
	bool operator<(const node&other){
		return x<other.x;
	}
}no[MAXN];

int par[MAXN];
struct xx{
	int val,id;
	bool operator<(const xx&other)const{
		return val<other.val||(val==other.val&&id<other.id);
	}
}a[MAXN];


int dp[MAXN];

int dfs(int u){
	if(par[u]==u)return 1;
	if(dp[u])return dp[u];
	dp[u]=dfs(par[u])+1;
	return dp[u];
}
int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d%d",&no[i].x,&no[i].w);
	}
	sort(no,no+N);
	for(int i=0;i<N;++i)no[i].id=i;

	for(int i=0;i<N;++i){
		a[i].val=no[i].x-no[i].w;
		a[i].id=no[i].id; 
	}
	sort(a,a+N);
	for(int i=0;i<N;++i)par[i]=i;

	for(int i=0;i<N;++i){
		int x=no[i].val-no[i].w;
		if(x>a[N-1].val)continue;//比最大值大

		int lo=i,hi=N-1;
		while(hi-lo>1){
			int mid=(hi+lo)/2;
			if(a[mid].val>=x)hi=mid;
			else lo=mid;
		}
		par[i]=a[hi].id;
		printf("par[%d]=%d\n",i,par[i]);
	}

	int res=0;
	for(int i=0;i<N-1;++i){
		res=max(res,dfs(i));
	}

	printf("%d\n",res);
	return 0;
}
