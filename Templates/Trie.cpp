#include<cstdio>
#include<cstring>
const int MAXN=6e5+7;
int ch[MAXN][26];
int cnt[MAXN];
struct Trie{ 
	int tot,root;
	int newnode(){ //动态初始化
		for(int i=0;i<26;++i)
			ch[tot][i]=0;
		cnt[tot++]=0;
		return tot-1;
	}
	Trie(){ 
		tot=0;
		root=newnode();
	}
	void insert(const char *s){ 
		int now=root;
		int len=strlen(s);len--;//fgets读入了换行
		for(int i=0;i<len;++i){ 
			if(!ch[now][s[i]-'a'])ch[now][s[i]-'a']=newnode();
			now=ch[now][s[i]-'a'];
			cnt[now]++;
		}
	}
	int query(const char *s){ 
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){ 
			if(!ch[now][s[i]-'a'])return 0;
			now=ch[now][s[i]-'a'];
		}
		return cnt[now];
	}
};

int main(){ 
	char s[128];
	Trie tr;
	while(fgets(s,128,stdin)){ 
		int len=strlen(s);
		if(len==1)break;
		tr.insert(s);
	}

	while(~scanf("%s",s)){ 
		printf("%d\n",tr.query(s));
	}
	return 0;
}
