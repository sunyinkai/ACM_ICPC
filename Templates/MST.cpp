//51nod 1212
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+7;
const int MAXM=5e4+7;
int par[MAXN];
struct edge{
	int u,v,c;
}es[MAXM];

int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i)
		scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].c);
	for(int i=1;i<=N;++i)par[i]=i;
	sort(es,es+M,[](const edge& a,const edge&b)->bool{
				return a.c<b.c;
			});
	int res=0;
	for(int i=0;i<M;++i){
		int a=find(es[i].u),b=find(es[i].v);
		if(a!=b){
			par[a]=b;
			res+=es[i].c;
		}
	}
	printf("%d\n",res);
	return 0;
}
