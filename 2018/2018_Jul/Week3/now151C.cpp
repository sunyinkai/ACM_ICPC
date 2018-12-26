#include<cstdio>
#include<cstring>
const int MAXN=2e4+7;
char s[MAXN];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	int flag=1,begin=0;
	for(int i=1;i<len;++i){
		if(s[i]=='1'){
			if(!begin)begin=i;
		}
		if(begin&&s[i]=='0')flag=0;
	}
	if(len==1){
		printf("1\n");
		return 0;
	}
	int res=0;
	if(!begin);
	else if(flag)res=len-begin;
	else res=len-1-begin;
	res+=len*(len-1)/2;
	printf("%d\n",res);
	return 0;
}
