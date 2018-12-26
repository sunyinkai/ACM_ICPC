#include<cstdio>
#include<cstring>
const int SIZE=4e5+7;
const long long mod=20071027;
int ch[SIZE][26],sz;
int isword[SIZE];
long long dp[SIZE];

void insert(const char *s,int len){ 
	int now=0; 
	for(int i=0;i<len;++i){ 
		if(!ch[now][s[i]-'a'])ch[now][s[i]-'a']=sz++;
		now=ch[now][s[i]-'a'];
	}
	isword[now]++;
}
void  query(int beg,const char *s,int len,long long &x){ 
	int now=0;
	for(int i=0;i<len;++i){ 
		if(!ch[now][s[i]-'a'])return ;
		now=ch[now][s[i]-'a'];
		if(isword[now]){ 
			x=(x+dp[beg+i+1])%mod;
		}
	}
}

char s[SIZE];
int main(){ 
	int test=1;
	while(~scanf("%s",s)){ 
		//init
		sz=1;
		memset(isword,0,sizeof(isword));
		memset(ch,0,sizeof(ch));

		int cnt;scanf("%d",&cnt);
		for(int i=0;i<cnt;++i){ 
			char t[128];
			scanf("%s",t);
			int len=strlen(t);
			insert(t,len);
		}

		memset(dp,0,sizeof(dp));
		int N=strlen(s);
		dp[N]=1;
		for(int i=N-1;i>=0;--i){ 
			query(i,s+i,N-i,dp[i]);
		}
		printf("Case %d: %lld\n",test,dp[0]);
		++test;
	}
	return 0;
}
