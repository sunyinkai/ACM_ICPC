//多重匹配
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int MAXN=1000+7,MAXM=507;
int uN,vN;
int g[MAXN][MAXN];
int linker[MAXM][MAXN];
bool used[MAXM];
int num[MAXM];
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
bool  isok(int k){
	int res=0;
	for(int i=0;i<vN;++i)linker[i][0]=0;
	for(int i=0;i<vN;++i)num[i]=k;
	for(int u=0;u<uN;++u){
		memset(used,false,sizeof(used));
		if(dfs(u)){
			++res;
		}
	}
	//printf("k=%d,res=%d\n",k,res);
	if(res==uN)return true;
	else return false;
}
int main(){
	int N,M;
	while(cin>>N>>M&&N+M){
		uN=N,vN=M;
		memset(g,0,sizeof(g));
		int maxSize=0;
		for(int i=0;i<N;++i){
			string name;cin>>name;
			while(1){
				int to;
				cin>>to;
				//printf("i=%d,to=%d\n",i,to);
				g[i][to]=1;
				char ch=getchar();
				if(ch=='\n')break;
			}
		}
		int lo=0,hi=uN+1;
		while(hi-lo>1){//最小化最大值
			int mid=(hi+lo)/2;
			if(isok(mid))hi=mid;
			else lo=mid;
		}
		cout<<hi<<endl;
	}
	return 0;
}
