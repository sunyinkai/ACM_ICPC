//动态初始化
//分治的思想
//需要考虑'\0'
#include<cstdio>
#include<cstring>
#include<cstdlib>
const int MAXN=5e6+7;
int ch[MAXN][63],cnt[MAXN];
int isword[MAXN];

struct Trie{ 
	int tot,root;

	Trie(){ 
		tot=0;
		root=newnode();
	}
	int idx(char ch){ 
		int x;
		if(ch>='a'&&ch<='z')x=ch-'a';
		else if(ch>='A'&&ch<='Z')x=26+ch-'A';
		else if(ch>='0'&&ch<='9')x=52+ch-'0';
		else x=62; //'\0'
		return x;
	}

	int newnode(){ 
		for(int i=0;i<63;++i)
			ch[tot][i]=0;
		cnt[tot]=0;
		isword[tot++]=0;
		return tot-1;
	}

	void insert(char *s){ 
		int len=strlen(s);
		int now=root;
		cnt[now]++;
		for(int i=0;i<=len;++i){ 
			int x=idx(s[i]);
			if(!ch[now][x]){ 
				ch[now][x]=newnode();
			}
			now=ch[now][x];
			cnt[now]++;
		}
		++isword[now];
	}

	long long dfs(int u,int depth){ 
		long long res=0;
		if(isword[u]){
			long long t=(long long)isword[u]*(isword[u]-1)/2*(2*depth);
			res+=t;
		}

		int q[63];
		int top=0,all=0; 
		for(int i=0;i<=62;++i)
				if(ch[u][i]){ 
					q[top++]=ch[u][i];
					all+=cnt[ch[u][i]];
				}
		for(int i=0;i<top;++i){ 
			all-=cnt[q[i]];
			long long t=(long long )cnt[q[i]]*all*(2*depth+1);
			res+=t;
		}
		for(int i=0;i<top;++i)
			res+=dfs(q[i],depth+1);
		return res;
	}

};

int main(){ 
	int N;
	int test=1;
	//freopen("in.txt","r",stdin);
	while(~scanf("%d",&N)&&N){ 
		Trie tire;
		while(N--){ 
			char s[1007];
			scanf("%s",s);
			tire.insert(s);
		}
		printf("Case %d: ",test++);
		printf("%lld\n",tire.dfs(0,0));
	}
	
	return 0;
}
