#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1007;
const int INF=1e9+7;

int dp[MAXN][13][13][13];
int visit[MAXN][13][13][13];
char s[MAXN],t[MAXN];
int len;
int dfs(int pos,int a,int b,int c){
	if(visit[pos][a][b][c])return dp[pos][a][b][c];
	if(pos==len)return 0;
	int num=t[pos]-'0',delta;
	int tt=INF;
	if(a<num){//up
		//向上
		delta=num-a;
		for(int i=0;i<=delta;++i){
			for(int j=0;j<=i;++j){
				tt=min(tt,dfs(pos+1,(b+i)%10,(c+j)%10,s[pos+3]-'0')+delta);
			}
		}
		delta=10-delta;
		//向下
		for(int i=0;i<=delta;++i){
			for(int j=0;j<=i;++j){
				tt=min(tt,dfs(pos+1,(b-i+10)%10,(c-j+10)%10,s[pos+3]-'0')+delta);
			}
		}

	}else{//down
		delta=a-num;
		for(int i=0;i<=delta;++i){
			for(int j=0;j<=i;++j){
				tt=min(tt,dfs(pos+1,(b-i+10)%10,(c-j+10)%10,s[pos+3]-'0')+delta);
			}
		}

		delta=10-delta;//向上
		for(int i=0;i<=delta;++i){
				for(int j=0;j<=i;++j){
					tt=min(tt,dfs(pos+1,(b+i+10)%10,(c+j+10)%10,s[pos+3]-'0')+delta);
				}
			}
	}

	visit[pos][a][b][c]=1;
	dp[pos][a][b][c]=tt;
	//printf("dp[%d][%d][%d][%d]=%d\n",pos,a,b,c,tt);
	return tt;
}

int main(){
	while(~scanf("%s%s",s,t)){
		len=strlen(s);
		memset(dp,0,sizeof(dp));
		memset(visit,0,sizeof(visit));
		printf("%d\n",dfs(0,s[0]-'0',s[1]-'0',s[2]-'0'));
	}
	return 0;
}
