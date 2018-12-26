#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
const int MAXN=2007;
const int INF=1e9+7;

const int MAXM=507;
char s[MAXN];
char t[MAXM];
int lenS,lenT;
int dp[MAXN][MAXN];
int ans[MAXN];

int getX(int lenS){
	int i=lenS,j=lenT;
	while(i>0&&j>0){
		while(i>0&&s[i]!=t[j])--i;
		--i;--j;
	}
	return i;
}
int main(){
	scanf("%s%s",s+1,t+1);
	lenS=strlen(s+1),lenT=strlen(t+1);
	for(int i=0;i<=lenS;++i)
		for(int j=0;j<=lenT;++j)
			dp[i][j]=INF;
	//dp[i][j]: 当前处理到i,匹配了j个的最小删除次数
	dp[0][0]=0;
	for(int i=1;i<=lenS;++i){
		for(int j=1;j<=i;++j){
			if(s[i]!=t[lenT]){//不等于最后一个
				dp[i][j]=dp[i-1][j];
			}else{
				int x=getX(i);
				printf("i=%d,x=%d\n",i,x);
				if(x==-1)dp[i][j]=dp[i-1][j];
				else{
					//发生匹配的位置
					dp[i][j]=min(dp[i-1][j],i-x-lenT+dp[x][j-1]);
				}
			}
			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}

	int  maxID=0;
	for(int j=1;j<=lenS;++j){
		printf("dp[lenS][%d]=%d\n",j,dp[lenS][j]);
		if(dp[lenS][j]!=0){
			int x=dp[lenS][j];//匹配了j个，最小删除次数
			ans[x]=j;
			maxID=x;
		}else break;
	}

	printf("0 ");
	int prev=0;
	for(int i=1;i<=maxID;++i){
		if(ans[i])prev=ans[i];
		printf("%d ",prev);
	}

	int cnt=0,all=0;
	for(int i=maxID+1;i<=lenS;++i){
		if(all%lenT==0)++cnt;
		printf("%d ",prev-cnt);
		++all;
	}
	return 0;
}
