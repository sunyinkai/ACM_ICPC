//tag: prefix_sum,nice_problem,contribution,binary_search
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int  MAXN=1e5+7;
char s[MAXN];
int f[MAXN];
int K;

long long solve(int len){
	long long ans=0;
	for(int i=1;i<=len;++i){
		//[s,e)
		int s=lower_bound(f+1,f+len+2,f[i]+1)-f;
		int e=lower_bound(f+1,f+len+2,f[i]+K+1)-f;
		if(f[e]==f[s])continue;
	//	printf("id:%d ans:%d\n",i,e-s);
		ans+=e-s;
	}
	return ans;
}

int main(){
	scanf("%d",&K);
	scanf("%s",s+1);
	int len=strlen(s+1);
	long long ans=0;
	for(int ch='a';ch<='z';++ch){
	//	printf("ch:%c\n",ch);
		memset(f,0,sizeof(f));
		//f[i]:[1..i)指定字符的数量
		for(int i=1;i<=len+1;++i){
			f[i]=f[i-1]+(s[i-1]==ch);
		}
		ans+=solve(len);
	}
	printf("%lld\n",ans);
	return 0;
}
