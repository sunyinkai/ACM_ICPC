#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=107;
const int MAXM=27;
const long long mod=20090717;
int ch[MAXN][26],fail[MAXN];
int match[MAXN];
queue<int>q;

int N,M,K;
long long dp[MAXM][MAXN][1<<10];//27*207*1024
struct AC{ 
	int tot,root;
	AC(){ 
		tot=0;
		root=newnode();
	}

	int newnode(){ 
		for(int i=0;i<26;++i)
			ch[tot][i]=0;
		match[tot++]=0;
		return tot-1;
	}
	void insert(char *s,int id){ 
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){ 
			int x=s[i]-'a';
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
		}
		match[now]=id;
	}
	void build(){ 
		while(!q.empty())q.pop();
		fail[0]=0;
		for(int i=0;i<26;++i){ 
			int v=ch[0][i];
			if(!v)ch[0][i]=0;
			else{ 
				fail[v]=0;
				q.push(v);
			}
		}
		while(!q.empty()){ 
			int now=q.front();q.pop();
			for(int i=0;i<26;++i){ 
				int v=ch[now][i];
				if(!v){ 
					ch[now][i]=ch[fail[now]][i];
				}else{ 
					fail[v]=ch[fail[now]][i];
					q.push(v);
				}
			}
		}
	}

	void solve(){ 
		//dp[i][j][k]://长度,当前位置,已经匹配的个数
		dp[0][0][0]=1;

		for(int i=0;i<N;++i){ //25 当前是的长度
			for(int now=0;now<tot;++now){ //107 处于自动机上什么位置
				for(int k=0;k<(1<<M);++k){//1024 已经匹配的集合
					if(!dp[i][now][k])continue;
					for(int x=0;x<26;++x){//x转移边 ,26
						int v=ch[now][x];
						//dp[i][now][k]
						int tmpk=k;
						int tmp=v;
						while(tmp){ 
							if(match[tmp])//匹配
								tmpk|=(1<<(match[tmp]-1));
							tmp=fail[tmp];
						}
						dp[i+1][v][tmpk]=(dp[i+1][v][tmpk]+dp[i][now][k])%mod;
					}
				}
			}
		}
		long long res=0;
		for(int now=0;now<tot;++now){ 
			for(int k=0;k<(1<<M);++k){ 
				int cnt=0;
				for(int i=0;i<M;++i)
					if(k&(1<<i))++cnt;
				if(cnt>=K)res=(res+dp[N][now][k])%mod;
			}
		}
		printf("%lld\n",res);
	}
};

int main(){ 
	while(~scanf("%d%d%d",&N,&M,&K)&&N+M+K){ 
		AC ac;	
		for(int i=0;i<M;++i){ 
			char s[30];scanf("%s",s);
			ac.insert(s,i+1);
		}
		ac.build();
		for(int i=0;i<=N;++i)
			for(int now=0;now<ac.tot;++now)
				for(int k=0;k<1024;++k)
					dp[i][now][k]=0;
		ac.solve();
	}
	return 0;
}
