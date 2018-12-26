#include<cstdio>
#include<cstring>
const int MAXN=1e4+7,MAXM=1e6+7;
char s[MAXN],t[MAXM];
typedef unsigned long long ull;
const ull seed1=1e9+7;
//询问s串是否在t串中出现过
//多hash可以写成函数
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s%s",s,t);
		int len=strlen(s);
		int size=strlen(t);
		ull power=1;
		for(int i=0;i<len;++i)power=power*seed1;
		ull val0=0,val2=0;
		for(int i=0;i<len;++i)
			val0=val0*seed1+s[i],val2=val2*seed1+t[i];
		int ans=0;
		for(int i=0;;++i){
			if(val2==val0)++ans;
			if(i+len>=size)break;
			val2=val2*seed1-t[i]*power+t[i+len];
		}
		printf("%d\n",ans);
	}
	return 0;

