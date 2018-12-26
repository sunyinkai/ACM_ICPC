#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
const int MAXN=5e6+7;
int ch[MAXN][2],cnt[MAXN];
long long ans=0;
struct Trie{
	int tot,root;
	Trie(){
		tot=0;
		root=newnode();
	}
	int newnode(){
		for(int i=0;i<2;++i)ch[tot][i]=0;
		cnt[tot++]=0;
		return tot-1;
	}
	void insert(const char *s){
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){
			int x=s[i]-'0';
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
			cnt[now]++;
		}
	}
	void dfs(int u,int depth){
	//	printf("cnt[u]=%d,depth=%d\n",cnt[u],depth);
		ans=max(ans,(long long)cnt[u]*depth);
		for(int i=0;i<2;++i){
			int v=ch[u][i];
			if(v)dfs(v,depth+1);
		}
	}
};
int main(){
	int T;scanf("%d",&T);
	while(T--){
		Trie tr;
		int N;scanf("%d",&N);
		for(int i=0;i<N;++i){
			char s[256];scanf("%s",s);
			tr.insert(s);
		}
		ans=0;	
		tr.dfs(0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
