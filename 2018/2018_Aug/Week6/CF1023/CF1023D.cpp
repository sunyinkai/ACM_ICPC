#include<cstdio>
#include<cstring>
const int MAXN=2e5+7; 
int a[MAXN],par[MAXN];
int visit[MAXN];
int que[MAXN],top;
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}

int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	for(int i=1;i<=N;++i)par[i]=i+1;
	for(int i=1;i<=N;++i){
		if(!visit[a[i]]){
			visit[a[i]]=i;
		}
	}
	for(int i=M;i>=1;--i){
		if(visit[i]){
			int x=visit[i];
			while(1){
				int y=par[x];
				if(a[y]!=a[x])break;
				x=par[x];
			}
		}
	}

	top=0;
	int x=0;
	while(par[x]!=N+1){
		x=par[x];
	}
	return 0;
}
