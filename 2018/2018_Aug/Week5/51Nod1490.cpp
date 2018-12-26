#include<cstdio>
#include<cstring>
const int MAXN=2e5+7;
char s[MAXN];
int ch[MAXN][27];
int flag[MAXN];
struct Trie{
	int tot,root;
	Trie(){
		tot=0;
		root=newnode();
	}
	int newnode(){
		for(int i=0;i<26;++i)
			ch[tot][i]=0;
		tot++;
		return tot-1;
	}
	int id(char ch){
		return ch-'a';
	}
	void insert(char *s){
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){
			int x=id(s[i]);
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
		}
	}
	//0 P态，1为N态
	int  dfs(int u){
	//	printf("u=%d\n",u);
		int tag=0;
		for(int i=0;i<26;++i){
			int v=ch[u][i];
			if(v){
				if(dfs(v)==0){//存在P
					tag=1;
				}
			}
		}
		return flag[u]=tag;
	}
};

int main(){
	int N,K;scanf("%d%d",&N,&K);
	Trie tr;
	for(int i=0;i<N;++i){
		scanf("%s",s);
		tr.insert(s);
	}
	int val=tr.dfs(0);
	if(val==0){
		printf("Second\n");
		return 0;
	}

	int hasZero=0,hasOne=0;
	for(int i=0;i<26;++i){
		int v=ch[0][i];
		if(v){
			if(flag[v]==0)hasZero=1;
			if(flag[v]==1) hasOne=1;
		//	printf("flag[%d]=%d\n",v,flag[v]);
		}
	}
	if(hasZero&&hasOne)printf("First\n");//可胜可败，一直输最后赢
	else printf(K%2==1?"First\n":"Second\n");//必胜,一人一把
	return 0;
}
