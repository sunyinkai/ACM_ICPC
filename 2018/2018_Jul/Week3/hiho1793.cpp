#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
const int MAXN=1e5+7;
char s[MAXN];
int cnt[2];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;++i){
		int x=s[i]-'0';
		cnt[x&1]++;
	}
	printf("%d\n",min(cnt[0],cnt[1]));
	return 0;
}
