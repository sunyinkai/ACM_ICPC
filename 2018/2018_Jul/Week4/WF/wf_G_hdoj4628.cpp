#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=18;
const int INF=1e9+7;
char s[MAXN];
int dp[1<<MAXN],len;
int isok[1<<MAXN];
void init(){
	for(int i=1;i<(1<<len);++i){
		int q[MAXN],tot=0;
		for(int j=0;j<len;++j)
			if((1<<j)&i)q[tot++]=j;
		isok[i]=true;
		for(int j=0;j<tot;++j){
			if(s[q[j]]!=s[q[tot-1-j]])isok[i]=false;
		}
	//	printf("%d:%d\n",i,isok[i]);
	}
}
int dfs(int S){
	if(dp[S]!=INF)return dp[S];
	int x=S;
	for(int i=x;i;){
		if(isok[i]){
			dp[S]=min(dp[S],dfs(S-i)+1);
		}
		i=(i-1)&S;
	}
	return dp[S];
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		len=strlen(s);
		dp[0]=0;
		init();
		for(int i=1;i<=(1<<len);++i)dp[i]=INF;
		printf("%d\n",dfs((1<<len)-1));
	}
	return 0;
}

