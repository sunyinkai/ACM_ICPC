#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=5007;
const int MAXE=2e5+7;
struct edge{
	int u,v,c;
	bool operator <(const edge&other)const{
		return c<other.c;
	}
}es[MAXE];

int par[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)par[i]=i;
	for(int i=0;i<M;++i){
		scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].c);
	}
	sort(es,es+M);
	int cnt=0,res=0;
	for(int i=0;i<M;++i){
		if(cnt==N-1)break;
		int u=find(es[i].u),v=find(es[i].v);
		if(u!=v){
			par[u]=v;
			res+=es[i].c;
			++cnt;
		}
	}
	if(cnt!=N-1)printf("orz\n");
	else printf("%d\n",res);
	return 0;
}
