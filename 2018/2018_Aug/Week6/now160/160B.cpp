#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=5e4+7;
struct edge{
	int to,next,num;
}es[MAXN*2];
int tot,head[MAXN];

void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int a,int b,int c){
	es[tot].to=b;
	es[tot].num=c;
	es[tot].next=head[a];
	head[a]=tot++;
}

unsigned int dp[MAXN],res;
//status=1,出现了.
unsigned int dfs(int u,int status,char ch){//到达该点的边
	//以u开头，中间全为小写字母，最后为.的个数
	//status已经有了.
	if(dp[u]!=0)return dp[u];
	if(ch=='.'){
		dp[u]=1;
		status=1;
	}
	if(status==1){
		if(ch=='_')dp[u]=1;
		else return 0;
	}

	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(status){
			if(es[i].num=='_'){
				dp[u]+=dfs(u,1,es[i].num);
			}
		}else{
			if(es[i].num>='a'&&es[i].num<='z'){
				dp[u]+=dfs(v,0,es[i].num);
			}else if(es[i].num=='.'){
				dp[u]+=dfs(v,0,'.');
				continue;
			}else if(es[i].num=='_'){
				dp[u]+=dfs(v,0,'_');
			}
		}
	}
	return dp[u];
}

void solve(int u){
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(es[i].num>='A'&&es[i].num<='Z'){
			res+=dp[v];
		}
	}
}
int main(){
	int N,M;scanf("%d%d",&N,&M);
	init();
	for(int i=0;i<M;++i){
		int a,b;char s[2];
		scanf("%d%d%s",&a,&b,s);
		char c=s[0];
		addEdge(a,b,c);
	}

	memset(dp,0,sizeof(dp));
	for(int i=1;i<=N;++i){
		dp[i]=dfs(i,0,0);
		cout<<"i "<<i<<" "<<dp[i]<<endl;
	}

	res=0;
	for(int i=1;i<=N;++i){
		solve(i);
	}
	cout<<res<<endl;
	return 0;
}
