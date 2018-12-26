//问每个串在目标串中出现的次数

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=2e4+7;
const int MAXM=1e6+7;
int ch[MAXN][26],fail[MAXN],wordId[MAXN];
int cnt[MAXN];
char t[MAXM];
char s[157][77];
struct AC{ 
	int tot,root;
	AC(){ 
		tot=1;
		root=0;
		memset(ch,0,sizeof(ch));
		memset(fail,0,sizeof(fail));
		memset(wordId,0,sizeof(wordId));
	}

	void insert(char *s,int id){ 
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){ 
			int x=s[i]-'a';
			if(!ch[now][x])ch[now][x]=tot++;
			now=ch[now][x];
		}
		wordId[now]=id;
	}
	
	void build(){ 
		int now=root;
		fail[root]=root;
		queue<int>q;
		while(!q.empty())q.pop();

		for(int i=0;i<26;++i){ 
			int v=ch[now][i];
			if(!v)ch[root][i]=root;
			else{ 
				fail[v]=root;
				q.push(v);
			}
		}
		while(!q.empty()){ 
			int now=q.front();q.pop();
			for(int i=0;i<26;++i){ 
				int v=ch[now][i];
				if(!v)ch[now][i]=ch[fail[now]][i];
				else{ 
					fail[v]=ch[fail[now]][i];
					//printf("fail[%d]=%d\n",v,fail[v]);
					q.push(v);
				}
			}
		}
	}
	void query(char *s){ 
		int len=strlen(s);
		int u=root;
		for(int i=0;i<len;++i){ 
			int x=s[i]-'a';
			u=ch[u][x];//匹配一个字符
			int temp=u;
			while(temp!=root){ 
				if(wordId[temp]){ 
	//				printf("tag\n");
					cnt[wordId[temp]]++;
				}
				temp=fail[temp];//沿着fail边往上走
			}
		}
	}
};

int main(){ 
	int N;
	while(~scanf("%d",&N)&&N){ 
		AC ac;
		for(int i=1;i<=N;++i){ 
			scanf("%s",s[i]);
			ac.insert(s[i],i);
		}
		ac.build();
		scanf("%s",t);
		memset(cnt,0,sizeof(cnt));
		ac.query(t);
		int res=0;
		for(int i=1;i<=N;++i) 
			if(cnt[i]>=res)res=cnt[i];

		printf("%d\n",res);
		for(int i=1;i<=N;++i){ 
			if(cnt[i]==res){ 
				printf("%s\n",s[i]);
			}
		}
	}
	return 0;
}
