#include<cstdio>
#include<cstring>
const int MAXN=4e6+1007;
int ch[MAXN][63],cnt[MAXN];
bool isword[MAXN];
long long ans;
struct Trie{
	int tot,root;
	Trie(){
		tot=0;
		root=newnode();
	}
	int newnode(){
		for(int i=0;i<63;++i)//26+26+10+1
			ch[tot][i]=0;
		isword[tot]=0;
		cnt[tot++]=0;
		return tot-1;
	}
	int idx(char ch){
		if(ch>='a'&&ch<='z')return ch-'a';
		if(ch>='A'&&ch<='Z')return 26+ch-'A';
		if(ch>='0'&&ch<='9')return 52+ch-'0';
		return 62;
	}
	void insert(const char *s){
		int len=strlen(s);
		int now=root;
		cnt[now]++;
		for(int i=0;i<=len;++i){
			int x=idx(s[i]);
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
			cnt[now]++;
		}
		isword[now]=1;
	}

	void dfs(int u,int depth){
		printf("depth[%d]=%d\n",u,depth);
		if(isword[u]){
			//printf("u=%d\n",u);
			ans+=(long long)cnt[u]*(cnt[u]-1)/2* 2*depth;
		}
		int q[63],top=0;
		int all=0;
		for(int i=0;i<63;++i)if(ch[u][i])q[top++]=ch[u][i],all+=cnt[ch[u][i]];
		for(int i=0;i<top;++i){
			all-=cnt[q[i]];
			ans+=(long long)cnt[q[i]]*all*(2*depth+1);
		}
		for(int i=0;i<top;++i)dfs(q[i],depth+1);
	}
};

int main(){
	int test=1;
	int N;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d",&N)&&N){
		Trie tr;
		while(N--){
			char s[1024];scanf("%s",s);
			tr.insert(s);
		}
		ans=0;
		printf("Case %d: ",test++);
		tr.dfs(0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
