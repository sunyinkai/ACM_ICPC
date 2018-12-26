#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+7;
int dp[MAXN];
int main(){
	char s[MAXN];
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;++i){
		int sum;
		for(int k=0;k<10;++k){
			if(i-k<0)continue;
			if(k==0)sum=s[i-k]-'0';
			else sum+=s[i-k]-'0';
			dp[i+1]=max(dp[i+1],dp[i-k]+(sum%3==0));
		}
	}
	printf("%d\n",dp[len]);
	return 0;
}
