#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+7;
struct edge{
	int from,to,cost;
}es[MAXN];

vector<int>G[MAXN];
int N,M;
int in[MAXN];
int top=0;
bool isok(int x){
	memset(in,0,sizeof(in));
	//build
	for(int i=0;i<M;++i){
		if(es[i].cost>x){
			G[es[i].from].push_back(es[i].to);
			in[es[i].to]++;
		}
	}
	//judge
	queue<int>q;
	for(int i=1;i<=N;++i)
		if(in[i]==0)q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		int len=G[u].size();
		for(int i=0;i<len;++i){
			int v=G[u][i];
			in[v]--;
			if(in[v]==0){
				q.push(v);
			}
		}
		G[u].clear();
	}
	int isok=1;
	for(int i=1;i<=N;++i){
		if(G[i].size()){
			isok=0;
		}
		G[i].clear();
	}
	return isok;
}

int top=0;
int ans[MAXN];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i)
		scanf("%d%d%d",&es[i].from,&es[i].to,&es[i].cost);
	int lo=-1,hi=1e9+7;
	while(hi-lo>1){
		int mid=(hi+lo)/2;
		if(isok(mid))hi=mid;
		else lo=mid;
	}
	isok(hi);
	printf("%d\n",hi);
	return 0;
}

