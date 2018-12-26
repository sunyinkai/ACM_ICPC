//match将匹配信息一层一层往下传
//不用每次往上跳,检测是不是某个单词的结尾
//检测匹配这个字符后有多少个单词满足条件
//比如:abc ,b  当前在b,如果下一条为c,有两个匹配
//往上跳的代码
/* int v=ch[u][i]
  int tag=0;
   while(v){ 
		if(isword[v])tag=1;
		v=fail[v];
   }
*/
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=407;
int ch[MAXN][62],fail[MAXN],match[MAXN];
queue<int>q;
int cnt;
double p[256],dp[MAXN][MAXN];

struct AC{ 
	int root,tot;
	AC(){ 
		tot=0;
		root=newnode();
	}

	int newnode(){ 
		for(int i=0;i<62;++i){ 
			ch[tot][i]=0;
		}
		match[tot++]=0;
		return tot-1;
	}
	int idx(char ch){ 
		int res;
		if(ch>='a'&&ch<='z')res= ch-'a';
		else if(ch>='A'&&ch<='Z')res=26+ch-'A';
		else res=52+ch-'0';
		return res;
	}

	void insert(char *s){ 
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){ 
			int x=idx(s[i]);
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
		}
		match[now]=1;
	}

	void build(){ 
		while(!q.empty())q.pop();
		fail[0]=0;
		for(int i=0;i<62;++i){ 
			int v=ch[0][i];
			if(!v)ch[0][i]=0;
			else{ 
				fail[v]=0;
				q.push(v);
			}
		}
		while(!q.empty()){ 
			int now=q.front();q.pop();
			for(int i=0;i<62;++i){ 
				int v=ch[now][i];
				if(!v)ch[now][i]=ch[fail[now]][i];
				else{ 
					fail[v]=ch[fail[now]][i];
					q.push(v);
					match[now]|=match[fail[now]];
					//match[v]|=match[fail[v]];
				}
			}
		}
	}

	void solve(){ 
		memset(dp,0,sizeof(dp));
		dp[0][0]=1.0;
		//dp[cnt][now];
		for(int k=0;k<cnt;++k){ 
			for(int now=0;now<tot;++now){
				if(!dp[k][now])continue;
				for(int i=0;i<62;++i){ 
					if(!p[i])continue;
					int to=ch[now][i];
					if(!match[to])dp[k+1][ch[now][i]]+=dp[k][now]*p[i];
				}
			}
		}

		double res=0.0;
		for(int i=0;i<tot;++i){ 
			if(match[i])continue;
			res+=dp[cnt][i];
		}
		printf("%.6f\n",res);
	}
};

int main(){ 
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){ 
		int N;scanf("%d",&N);
		char s[25];
		AC ac;
		for(int i=0;i<N;++i){ 
			scanf("%s",s);
			ac.insert(s);
		}
		ac.build();

		int M;scanf("%d",&M);
		memset(p,0,sizeof(p));
		for(int i=0;i<M;++i){ 
			char ch[9];double x;
			scanf("%s%lf",ch,&x);
			p[ac.idx(ch[0])]=x;
		//	printf("%c : %f\n",ch,x);
			getchar();
		}
		scanf("%d",&cnt);
		printf("Case #%d: ",test);
		ac.solve();
	}
	return 0;
}
