#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=1e5+7;
int depth[MAXN],cnt[MAXN];
int in[MAXN],out[MAXN],dfs_clock=0;
vector<int>G[MAXN],h[MAXN];

void dfs(int u,int pre,int dep){
	in[u]=++dfs_clock;//dfs order
	depth[u]=dep;
	h[dep].push_back(in[u]);
	cnt[dep]++;
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(v==pre)continue;
		dfs(v,u,dep+1);
	}
	out[u]=dfs_clock;
}

LL bit[MAXN];
int N,Q; 
inline int lowbit(int i){return i&-i;}
void add(int p,LL x){
	for(int i=p;i<=N;i+=lowbit(i))bit[i]+=x;
}

LL sum(int p){
	LL res=0;
	for(int i=p;i;i-=lowbit(i))res+=bit[i];
	return res;
}

int q[MAXN],top=0;
LL lazy[MAXN];
int main(){
	scanf("%d%d",&N,&Q);
	for(int i=1;i<N;++i){
		int a,b;scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1,-1,0);
	int block=sqrt(N);

	//init();
	for(int i=0;i<=N;++i){
		if(cnt[i]>block){
			q[top++]=i;
			sort(h[i].begin(),h[i].end());
		}
		/*printf("cnt[i]=%d\n",cnt[i]);
		for(int j=0;j<cnt[i];++j){
			printf("%d ",h[i][j]);
		}
		printf("\n");*/
	}

	
	while(Q--){
		int qq;scanf("%d",&qq);
		if(qq==1){
			int L,x;scanf("%d%d",&L,&x);
			if(cnt[L]<=block){//the count <= block
				for(int i=0;i<cnt[L];++i){
					int u=h[L][i];
					add(u,x);
	//				printf("add %d:%d\n",u,x);
				}
			}else{//the count>block ,then the num will not over block
				lazy[L]+=x;
			}
		}else{
			int x;scanf("%d",&x);
			int l=in[x],r=out[x];
			LL res=0;
			res=sum(r)-sum(l-1);//BIT
	//		printf("l=%d,r=%d,res=%lld\n",l,r,res);
			for(int i=0;i<top;++i){
	//			printf("q[i]=%d\n",q[i]);
				int x=lower_bound(h[q[i]].begin(),h[q[i]].end(),l)-h[q[i]].begin();
				int y=upper_bound(h[q[i]].begin(),h[q[i]].end(),r)-h[q[i]].begin();
	//			printf("x=%d,y=%d\n",x,y);
				res+=(long long)(y-x)*lazy[q[i]];
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}
