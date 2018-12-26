#include<cstdio>
#include<cstring>
//Trie的写法

const int MAXM=4e5+7;
char s[MAXM];
int isword[MAXM];
long long dp[MAXM];
int ch[MAXM][26];
const long long mod=20071027;
struct Trie{
	int tot,root;
	Trie(){
		tot=0;
		root=newnode();
	}
	int newnode(){
		for(int i=0;i<26;++i)ch[tot][i]=0;
		isword[tot++]=0;
		return tot-1;
	}
	void insert(const char *s){
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){
			int x=s[i]-'a';
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
		}
		isword[now]++;
	}
	long long  query(const char* s,int id){
		int len=strlen(s);
	//	printf("s=%s,len=%d\n",s,len);
		int now=root;
		long long ans=0;
		for(int i=0;i<len;++i){
			int x=s[i]-'a';
			if(!ch[now][x])return ans%mod;
			now=ch[now][x];
			if(isword[now]){
				ans=(ans+dp[id+i+1]*isword[now])%mod;
			}
		}
		return ans%mod;
	}

	void solve(){
		int len=strlen(s);
		dp[len]=1;
		for(int i=len-1;i>=0;--i){
			dp[i]=query(s+i,i)%mod;
		}
		printf("%lld\n",dp[0]%mod);
	}
};

int main(){
	int test=1;
	while(~scanf("%s",s)){
		Trie tr;
		int N;scanf("%d",&N);
		while(N--){
			char t[107];scanf("%s",t);
			tr.insert(t);
		}
		printf("Case %d: ",test++);
		tr.solve();
	}
	return 0;
}
