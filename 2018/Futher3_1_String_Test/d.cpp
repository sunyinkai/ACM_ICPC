#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e6+7;
int ch[MAXN][2],sz;
int val[MAXN];
void insert(const char*s){ 
	int len=strlen(s);
	int now=0;
	for(int i=0;i<len;++i){ 
		if(!ch[now][s[i]-'0'])ch[now][s[i]-'0']=sz++;
		now=ch[now][s[i]-'0'];
		val[now]++;
	}
}
int ans=0;
void dfs(int u,int depth){ 
	ans=max(ans,depth*val[u]);
	if(ch[u][0])dfs(ch[u][0],depth+1);
	if(ch[u][1])dfs(ch[u][1],depth+1);
}
int main(){ 
	int T;scanf("%d",&T);
	while(T--){ 
		sz=1;
		memset(ch,0,sizeof(ch));
		memset(val,0,sizeof(val));

		int N;scanf("%d",&N);
		for(int i=0;i<N;++i){ 
			char s[256];
			scanf("%s",s);
			insert(s);
		}
		ans=0;
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}
