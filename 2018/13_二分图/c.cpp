#include<cstdio>
#include<cstring>
#define swap(a,b) (a^=b^=a^=b)
const int MAXN=507;
int g[MAXN][MAXN],linker[MAXN],used[MAXN];
int uN,vN;
int dfs(int u){
	for(int v=1;v<=vN;++v){
		if(g[u][v]&&!used[v]){
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
}
bool  hungary(){
	memset(linker,-1,sizeof(linker));
	for(int u=1;u<=uN;++u){
		memset(used,false,sizeof(used));
		if(!dfs(u))return false;
	}
	return true;
}

int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){

		int n,s;scanf("%d%d",&n,&s);
		printf("Case #%d: ",test);
		if(s<n)swap(s,n);
		if(n>=MAXN-5){
			printf("No\n");
		}else{
			uN=vN=n;
			memset(g,0,sizeof(g));
			for(int i=1;i<=n;++i){
				int x=s+i;
				for(int j=1;j<=n&&j*j<=x;++j){
					if(x%j==0){
						if(j<=n)g[i][j]=1;
						if(x/j<=n)g[i][x/j]=1;
					}
				}
			}
			if(hungary())printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
