#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
struct Trie{
private:
	char ch[MAXN][26];
	int val[MAXN];
	int tot;//tot为第i个节点
public:
	Trie(){
		memset(ch,0,sizeof(ch));
		memset(val,0,sizeof(val));
		tot=1;
	}
	void insert(const char *s){
		int len=strlen(s);
		int u=0;//0号节点为根节点
		for(int i=0;i<len;++i){
			if(!ch[u][s[i]-'a'])ch[u][s[i]-'a']=tot++;
			u=ch[u][s[i]-'a'];
			val[u]++;
		}
	}
	int query(const char *s){
		int u=0;
		int len=strlen(s);
		for(int i=0;i<len;++i){
			if(!ch[u][s[i]-'a'])return 0;
			u=ch[u][s[i]-'a'];
		}
		return val[u];
	}
};

int main(){
	int M,N;scanf("%d%d",&N,&M);
	Trie a;
	for(int i=0;i<N;++i){
		char s[30];
		scanf("%s",s);
		a.insert(s);
	}
	for(int i=0;i<M;++i){
		char s[30];
		scanf("%s",s);
		printf("%d\n",a.query(s)); }
	return 0;
}
