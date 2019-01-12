#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char s[60];scanf("%s",s);
	int len=strlen(s);
	char ans[60],top=0;
	memset(ans,0,sizeof(ans));
	int x=(len+1)/2-1;
	ans[top++]=s[x];
	for(int i=1;i<=x;++i){
		ans[top++]=s[x+i];
		ans[top++]=s[x-i];
	}
	if(len%2==0)ans[top++]=s[len-1];
	printf("%s\n",ans);
	return 0;
}
