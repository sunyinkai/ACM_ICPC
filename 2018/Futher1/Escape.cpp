#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
const int MAXM=13;
int uN,vN;
int g[MAXN][MAXM];
int linker[MAXM][MAXN];
bool used[MAXM];
int num[MAXM];
int read(){ 
	int res=0;
	char ch;
	while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-'0';
	return res;
}
bool dfs(int u){ 
	for(int v=0;v<vN;v++)
		if(g[u][v]&&!used[v]){ 
			used[v]=true;
			if(linker[v][0]<num[v]){ 
				linker[v][++linker[v][0]]=u;
				return true;
			}
			for(int i=1;i<=num[0];++i){ 
				if(dfs(linker[v][i])){ 
					linker[v][i]=u;
					return true;
				}
			}
	}
	return false;
}
int hungary(){ 
	int res=0;
	for(int i=0;i<vN;++i) 
		linker[i][0]=0;
	for(int u=0;u<uN;++u){ 
		memset(used,false,sizeof(used));
		if(dfs(u))++res;
		else return res;
	}
	return res;
}

int main(){ 
	int N,M;
	while(~scanf("%d%d",&N,&M)){ 
		getchar();
		for(int i=0;i<N;++i){ 
			for(int j=0;j<M;++j){ 
				g[i][j]=read();
			}
		}
		for(int i=0;i<M;++i)num[i]=read();
		uN=N,vN=M;
		int res=hungary();

		if(res==N)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
