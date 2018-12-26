#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
const int MAXN=1007;
char a[MAXN],b[MAXN];
int dp[MAXN][MAXN];
int main(){
	while(~scanf("%s",a)){
		int len=strlen(a);	
		for(int i=0;i<len;++i){
			b[i]=a[len-1-i];
		}
		b[len]='\0';
		memset(dp,0,sizeof(dp));
		for(int i=0;i<len;++i){
			for(int j=0;j<len;++j){
				if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;
				else dp[i+1][j+1]=max(dp[i][j+1],dp[j][i+1]);
			}
		}
		printf("%d\n",dp[len][len]);
	}
	return 0;
}
