#include<cstdio>
#include<cstring>
const int MAXN=1e6+7;
const long long mod=1e9+7;
char s[MAXN];
int  id[27];//某字符最早出现的位置
long long dp[26];
//dp[i][j]:当前处理到i位置，以j结尾的子序列有多少个
int main(){
	int N,M;scanf("%d%d",&N,&M);
	scanf("%s",s);
	int len=strlen(s);
	long long sum=1;
	for(int i=0;i<len;++i){
		int x=s[i]-'a';
		id[x]=i+1;
		long long next=0;
		for(int j=0;j<26;++j){
			if(j==x){
				dp[j]=sum;
			}else{
				dp[j]=dp[j];
			}
			next=(next+dp[j])%mod;
		}
		sum=(next+1)%mod;//1为空字符
	}

	//printf("%d\n",sum);
	//枚举加的字母?不可行，因为数值已经取过模，无法枚举
	//选最久没有出现的那个？
	for(int i=0;i<N;++i){
		int mx=-1;
		for(int j=0;j<M;++j){
			if(mx==-1||id[j]<id[mx])mx=j;
		}
		id[mx]=len+i+1;
		long long next=0;
		for(int j=0;j<26;++j){
			if(j==mx)dp[j]=sum;
			else dp[j]=dp[j];
			next=(next+dp[j])%mod;
		}
		sum=(next+1)%mod;
	}
	printf("%lld\n",sum);
	return 0;
}
