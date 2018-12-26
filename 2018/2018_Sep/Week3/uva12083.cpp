#include<bits/stdc++.h>
using namespace std;

const int MAXN=507;
int h[MAXN];
char sex[MAXN][107],music[MAXN][107],sport[MAXN][107];
int linker[MAXN],visit[MAXN];
int g[MAXN][MAXN];
//如果两个人不能同时去就连一条边
int N;
bool dfs(int u){
	for(int v=0;v<N;++v){
		if(g[u][v]&&!visit[v]){
			visit[v]=true;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0;i<N;++i)
			scanf("%d%s%s%s",&h[i],sex[i],music[i],sport[i]);
		memset(g,0,sizeof(g));
		for(int i=0;i<N;++i){
			for(int j=i+1;j<N;++j){
				bool isok=false;
				if(abs(h[i]-h[j])>40)isok=true;
				if(sex[i][0]==sex[j][0])isok=true;
				if(strcmp(music[i],music[j])!=0)isok=true;
				if(strcmp(sport[i],sport[j])==0)isok=true;
				if(!isok){
					if(sex[i][0]=='M'&&sex[j][0]=='F')g[i][j]=1;
					else if(sex[i][0]=='F'&&sex[j][0]=='M')g[j][i]=1;
				}
			}
		}

		memset(linker,-1,sizeof(linker));
		int ans=0;
		for(int i=0;i<N;++i){
			memset(visit,0,sizeof(visit));
			if(dfs(i))++ans;
		}

		printf("%d\n",N-ans);
	}
	return 0;
}
