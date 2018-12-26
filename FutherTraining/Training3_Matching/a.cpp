#include<cstdio>
#include<cstring>
#define swap(a,b) (a^=b^=a^=b)
//以行与列为点,可以放的连边
const int MAXN=30;
int uN,vN;//uN,左边数量,vN右边数量
int g[MAXN][MAXN];//i->j左边向右边匹配
int linker[MAXN];
int R[MAXN][MAXN],C[MAXN][MAXN];
bool used[MAXN];
bool dfs(int u){//从u点出发能不能找到增广路,腾位置
	for(int v=0;v<vN;v++){
		if(g[u][v]&&!used[v]){
			used[v]=true;//标记为搜索过
			if(linker[v]==-1||dfs(linker[v])){//如果前面那个男生可以腾位置,或者v名花无主,linker[v]==-1,表示v还没有匹配过
				linker[v]=u;//匹配v,u
				return true;
			}
		}
	}
	return false;
}
int hungary(){
	int res=0;
	memset(linker,-1,sizeof(linker));
	for(int u=0;u<uN;u++){
		memset(used,false,sizeof(used));
		if(dfs(u))++res;//找到一条增广路
	}
	return res;
}

char s[6][6];
int main(){
	int N;
	while(scanf("%d",&N)&&N){
		uN=N*N,vN=N*N;
		for(int i=0;i<N;++i)scanf("%s",s[i]);
		memset(g,0,sizeof(g));
		int row=0,col=0;//每个区块的编号
		for(int i=0;i<N;i++,row++){
			for(int j=0;j<N;j++){
				if(s[i][j]=='X'&&j+1<N&&s[i][j+1]!='X')row++;
				R[i][j]=row;
			}
		}
		for(int j=0;j<N;++j,col++){
			for(int i=0;i<N;++i){
				if(s[i][j]=='X'&&i+1<N&&s[i+1][j]!='X')col++;
				C[i][j]=col;
			}
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(s[i][j]!='X')g[R[i][j]][C[i][j]]=1;
			}
		}
		printf("%d\n",hungary());
	}
	return 0;
}

