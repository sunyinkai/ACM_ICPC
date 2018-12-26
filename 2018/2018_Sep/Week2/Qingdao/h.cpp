#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
char s[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);//s_1....s_len
		int len=strlen(s+1);
		long long res=0;
		for(int i=1;i<len;++i){
		//	printf("s[i]=%c,s[i+1]=%c\n",s[i],s[i+1]);
			res+=(long long)i*(len-i)*(long long)(s[i]==s[i+1]);
			if(s[i]=='0'){
				res+=(long long)len-i+1;
			}
		}
		if(s[len]=='0')++res;
		for(int i=1;i<=len;++i)
			res+=(long long)i*(len-i+1);
		printf("%lld\n",res);
	}
	return 0;
}
