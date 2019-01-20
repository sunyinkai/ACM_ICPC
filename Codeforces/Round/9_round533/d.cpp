#include<bits/stdc++.h>
using namespace std;
const int MAXN=1007;
int visit[MAXN][MAXN];
int v[10];
char s[MAXN][MAXN];
struct node{
	node(int a,int b,int c):x(a),y(b),id(c){}
	node(){}
	int x,y;
	int id;
	bool operator<(const node&other)const{
		return id<other.id;
	}
}no[MAXN*MAXN],add[MAXN*MAXN];

queue<node>q[10];
int ans[15];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int main(){
	int N,M,P;scanf("%d%d%d",&N,&M,&P);
	for(int i=1;i<=P;++i)
		scanf("%d",&v[i]);
	for(int i=0;i<N;++i)
		scanf("%s",s[i]);
	//input

	int top=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(s[i][j]=='#'){
				visit[i][j]=13;
			}

			if(s[i][j]>='1'&&s[i][j]<='9'){
				int num=s[i][j]-'0';
				no[++top]=node(i,j,num);
				visit[i][j]=num;
			}
		}
	}

	sort(no+1,no+top+1);
	for(int i=1;i<=top;++i){
		q[no[i].id].push(no[i]);
	}

	//init
	while(1){
		bool isok=false;
		for(int id=1;id<=P;++id){
			for(int cnt=0;cnt<v[id];++cnt){//bfs s times
				int top=0;
				while(!q[id].empty()){
					node no=q[id].front();q[id].pop();
					int xx=no.x,yy=no.y;
					for(int dir=0;dir<4;++dir){
						int nx=xx+dx[dir];
						int ny=yy+dy[dir];
						if(nx>=0&&nx<N&&ny>=0&&ny<M&&!visit[nx][ny]){
							isok=true;
							visit[nx][ny]=id;
							add[top++]=node(nx,ny,id);
						}
					}
				}
				for(int i=0;i<top;++i)
					q[id].push(add[i]);
				if(top==0)break;
			}
		}
		if(!isok)break;
	}


	//print ans
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			ans[visit[i][j]]++;
	for(int i=1;i<=P;++i)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
