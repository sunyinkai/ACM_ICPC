#include<cstdio>
#include<cstring>
const int MAXN=507;
char s[MAXN][MAXN];
int N,M,K;
int visit[MAXN][MAXN];
int dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
int size[MAXN*MAXN];
int dfs(int x,int y,int col){
	visit[x][y]=col;
	int size=1;
	for(int i=0;i<4;++i){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&nx<N&&ny>=0&&ny<M&&s[nx][ny]=='.'&&!visit[nx][ny]){
			size+=dfs(nx,ny,col);
		}
	}
	return size;
}

char ans[MAXN][MAXN];
bool hasDone[MAXN][MAXN];
void dfs2(int x,int y){
	hasDone[x][y]=1;
	int size=0;
	for(int i=0;i<4;++i){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&nx<N&&ny>=0&&ny<M&&s[nx][ny]=='.'&&!hasDone[nx][ny]){
			dfs2(nx,ny);
			++size;
		}
	}
	if(K){
		ans[x][y]='X';
		K--;
	}
	if(size==0)return;
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<N;++i)scanf("%s",s[i]);
	int top=0;
	int maxSIZe=0,maxCol=0 ;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(s[i][j]=='.'&&!visit[i][j]){
				++top;
				size[top]=dfs(i,j,top);
				if(size[top]>maxSIZe){
					maxSIZe=size[top];//找出最大的联通快
					maxCol=top;
				}
			}
		}
	}
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			ans[i][j]=s[i][j];//copy

	if(top>1){
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				ans[i][j]=s[i][j];
				if(s[i][j]=='.'&&visit[i][j]!=maxCol){
					ans[i][j]='X';
					--K;
					if(K==0)break;
				}
			}
			if(K==0)break;
		}
	}//多个联通块的情况

	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(K==0)break;
			if(s[i][j]=='.'&&visit[i][j]==maxCol){
				dfs2(i,j);
			}
		}
		if(K==0)break;
	}

	for(int i=0;i<N;++i)
		printf("%s\n",ans[i]);
	return 0;
}
