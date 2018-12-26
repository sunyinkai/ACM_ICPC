#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
const int MAXN=1e3+7;
int x[3],y[3];
int tx[MAXN*MAXN],ty[MAXN*MAXN];
int visit[MAXN][MAXN];
int pre[MAXN][MAXN];

int dx[4]={-1,1,0,0,},dy[4]={0,0,1,-1};
struct node{
	int x,y;
	node(int _x,int _y){
		x=_x;y=_y;
	}
};

queue<node>q;
int k;
int done[MAXN][MAXN];
void dfs(int num){
	int xx=num/1001,yy=num%1001;
	tx[k]=xx;ty[k++]=yy;
	if(xx==x[2]&&yy==y[2])return;
	dfs(pre[xx][yy]);
}

int main(){
	for(int i=0;i<3;++i)
		scanf("%d%d",&x[i],&y[i]);

	k=0;
	if(x[0]>x[1]){
		swap(x[0],x[1]);
		swap(y[0],y[1]);
	}//x[0]<x[1]
	for(int i=x[0];i<=x[1];++i){
		if(visit[i][y[0]])continue;
		visit[i][y[0]]=1;
		tx[k]=i;ty[k++]=y[0];
	}
	if(y[0]<y[1]){
		for(int i=y[0];i<=y[1];++i){
			if(visit[x[1]][i])continue;
			visit[x[1]][i]=1;
			tx[k]=x[1];ty[k++]=i;
		}
	}
	else{
		for(int i=y[0];i>=y[1];--i){
			if(visit[x[1]][i])continue;
			visit[x[1]][i]=1;
			tx[k]=x[1];ty[k++]=i;
		}
	}
	//
	q.push(node(x[2],y[2]));
	pre[x[2]][y[2]]=-1;
	int num;
	while(!q.empty()){
		node u=q.front();q.pop();
		int tx=u.x,ty=u.y;
		num=0;
		for(int i=0;i<4;++i){
			int nx=tx+dx[i],ny=ty+dy[i];
			if(pre[nx][ny])continue;
				pre[nx][ny]=tx*1001+ty;
				q.push(node(nx,ny));
			if(visit[nx][ny]){
				num=pre[nx][ny];
				break;
			}
		}
		if(num)break;
	}

	dfs(num);
	printf("%d\n",k);
	for(int i=0;i<k;++i)
		printf("%d %d\n",tx[i],ty[i]);
	return 0;
}
