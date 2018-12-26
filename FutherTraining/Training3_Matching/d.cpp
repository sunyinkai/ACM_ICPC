//多重匹配
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int MAXN=1000+7,MAXM=507;
const int INF=1e9+7;
int uN,vN;
int g[MAXN][MAXN];//牛->机器
int linker[MAXM][MAXN];
bool used[MAXM];
int num[MAXM];
int d[MAXN][MAXN];
int K,C,M;

bool dfs(int u){
	for(int v=0;v<vN;++v){
		if(g[u][v]&&!used[v]){
			used[v]=true;
			if(linker[v][0]<num[v]){
				linker[v][++linker[v][0]]=u;
				return true;
			}
			for(int i=1;i<=linker[v][0];++i){
				if(dfs(linker[v][i])){
					linker[v][i]=u;
					return true;
				}
			}
		}
	}
	return false;
}
bool  isok(int mid){
	if(mid==1){
	//	printf("tag\n");

	}
	int res=0;
	for(int i=0;i<vN;++i)linker[i][0]=0;
	//build grapha
	for(int i=K;i<K+C;++i){//牛
		for(int j=0;j<K;++j){//机器
			if(d[i][j]<=mid){
				g[i-K][j]=1;//牛->机器
		//		printf("%d->%d,dis=%d\n",i-K,j,d[i][j]);
			}
			else g[i-K][j]=0;
		}
	}
	
	for(int u=0;u<uN;++u){
		memset(used,false,sizeof(used));
		if(dfs(u)){
			++res;
		}
	}
	//printf("mid=%d,res=%d\n",mid,res);
	if(res==uN)return true;
	else return false;
}
int main(){
	while(~scanf("%d%d%d",&K,&C,&M)){
		uN=C,vN=K;
		for(int i=0;i<K+C;++i)//机器+牛
			for(int j=0;j<K+C;++j){
				scanf("%d",&d[i][j]);
				if(d[i][j]==0)d[i][j]=INF;
			}
		
		//floyd
		for(int i=0;i<vN;++i)num[i]=M;
		for(int k=0;k<K+C;++k)
			for(int i=0;i<K+C;++i)
				for(int j=0;j<K+C;++j)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

		//二分
		int lo=0,hi=1e5+7;
		while(hi-lo>1){
			int mid=(hi+lo)/2;
			if(isok(mid))hi=mid;
			else lo=mid;
		}
		printf("%d\n",hi);
	}
	return 0;
}
