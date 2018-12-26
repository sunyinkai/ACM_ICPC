#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
const int MAXN=4e5+7;
const int MAXM=3e5+7;
const long long mod=20071027;
int tot=1;
char ch[MAXN][26];
bool isWord[MAXN];
long long dp[MAXM];
inline void insert(const char *s){
	int u=0;
	int len=strlen(s);
	for(int i=0;i<len;++i){
		if(!ch[u][s[i]-'a'])ch[u][s[i]-'a']=tot++;
		u=ch[u][s[i]-'a'];
	}
	isWord[u]=1;
}
void init(){
	tot=1;
	memset(ch,0,sizeof(ch));
	memset(isWord,0,sizeof(isWord));
	memset(dp,0,sizeof(dp));
}
int now;
inline void query(const char *s,int len){
	int u=0;
	for(int i=0;i<len;++i){
		u=ch[u][s[i]-'a'];
		if(!u){
			return ;
		}	
		if(isWord[u]){
			dp[now]=(dp[now]+dp[now+i+1])%mod;
		}	
	}
}
char s[MAXM];
int main(){
	int test=1;
	while(scanf("%s",s)!=EOF){
		init();
		int lenS=strlen(s);
		int N;scanf("%d",&N);
		for(int i=0;i<N;++i){
			char tmp[102];
			scanf("%s",tmp);
			insert(tmp);
		}//insert
		dp[lenS]=1;
		for(now=lenS-1;now>=0;--now){
			query(s+now,lenS-now);
		}
		printf("Case %d: %lld\n",test,dp[0]%mod);
		++test;
	}
	return 0;
}
