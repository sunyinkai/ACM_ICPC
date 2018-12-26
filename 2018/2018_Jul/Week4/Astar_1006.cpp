#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXE=107;
const int INF=1e9+7;

struct node{
	int u,v,val;
	char col;
	bool operator<(const node&other)const{
		return val<other.val;
	}
}es[MAXE];

int par[MAXE];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}

int N,M;
void solve(char col1,char col2,int &res, int k){
	int q[MAXE];
	for(int i=0;i<=N;++i)par[i]=i;
	for(int i=0;i<=M;++i)q[i]=0;
	int cnt=k;//需要使用的边数
	int tmp=0;
	for(int i=0;i<M&&cnt;++i){
		if(es[i].col== col1 ||es[i].col==col2){
			int x=find(es[i].u);
			int y=find(es[i].v);
			if(x!=y){
				q[i]=1;//边是否已经被使用
				tmp+=es[i].val;
				par[x]=y;
				--cnt;
			}
		}
	}

	int block=0;
	for(int i=1;i<=N;++i){
		par[i]=find(par[i]);
		if(par[i]==i)++block;
	}
	if(block>1)return ;
	for(int i=0;i<M&&cnt;++i){
		if(!q[i]){
			tmp+=es[i].val;
			q[i]=1;
			--cnt;
		}
	}
	res=min(res,tmp);
}

int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		scanf("%d%d",&N,&M);
		for(int i=0;i<M;++i){
			scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].val);
			char s[3];scanf("%s",s);
			es[i].col=s[0];
		}//input
		sort(es,es+M);
		printf("Case #%d:\n",test);
		for(int k=1;k<=M;++k){
			if(k<N-1){//无法构成树
				printf("-1\n");
				continue;
			}
			int res=INF;
			solve('R','G',res,k);
			solve('G','B',res,k);
			if(res==INF)printf("-1\n");
			else printf("%d\n",res);
		}
	}
	return 0;
}
