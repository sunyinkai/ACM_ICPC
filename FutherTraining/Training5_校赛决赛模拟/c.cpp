#include<cstdio>
#include<cstring>
const int MAXN=307;
const int INF=-1e9+7;
int par[MAXN*2];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
void unit(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		par[x]=y;
	}
}

int a[MAXN],tot,cnt[MAXN],visit[MAXN];
int n,p,q;
int dp[MAXN][MAXN];//前i个物品巧好装好j容量背包的方法数
void solve(){
	tot=1;
	for(int i=1;i<MAXN;++i){
		if(!visit[i])continue;
		int x=find(i);
		cnt[x]++;
		printf("cnt[%d]=%d\n",x,cnt[x]);
	}
	for(int i=1;i<MAXN;++i){
		if(cnt[i]){
			a[tot++]=cnt[i];
			printf("num:%d\n",cnt[i]);//;每个块的人数
		}
	}//并查集 

	for(int i=1;i<tot;++i){//0-tot
		for(int j=0;j<=p;++j){//max=p;
			dp[i][j]=-INF;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<tot;++i){
		for(int j=0;j<=p;++j){
			if(j>=a[i])dp[i][j]+=dp[i-1][j-a[i]];
		}
	}
}
int main(){
	while(scanf("%d%d%d",&n,&p,&q)&&n+p+q){
		for(int i=1;i<2*MAXN;++i)par[i]=i;
		memset(visit,0,sizeof(visit));
		bool hasAns=true;

		for(int i=0;i<n;++i){
			int x,y;char s[5];
			scanf("%d%d%s",&x,&y,s);
			visit[x]=visit[y]=1;
			if(s[0]=='y'){
				if(find(x)==find(y+301)||find(x+301)==find(y))hasAns=false;
				unit(x,y);
				unit(x+301,y+301);
			}else{
				if(find(x)==find(y)||find(x+301)==find(y+301))hasAns=false;
				unit(x,y+301);
				unit(x+301,y);
			}
		}//input

		if(!hasAns){
			printf("no\n");//自相矛盾
			continue;
		}
		solve();
	}
	return 0;
}
