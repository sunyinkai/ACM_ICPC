#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
const long long mod=1e9+7;
char s[MAXN];
char t[MAXN];
int q[MAXN];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	int top=0;
	for(int i=0;i<len;++i){
		if(s[i]=='a'||s[i]=='b')
			t[top++]=s[i];
	}

	t[top++]='\0';
	int cnt=0;
	int num=0;
	for(int i=0;i<top;++i){
		if(t[i]=='a')++num;
		else{
			q[cnt++]=num;
			num=0;
		}
	}
	q[cnt++]=num;

	long long ans=1;
	for(int i=0;i<cnt;++i)
		ans=ans*(1+q[i])%mod;
	printf("%lld\n",(ans-1+mod)%mod);
	return 0;
}
