#include<cstdio>
#include<cstring>
const int MAXN=1e6+7;
char s[MAXN],t[MAXN];
int main(){
	while(~scanf("%s%s",s,t)){
		int lenS=strlen(s);//i
		int lenT=strlen(t);//j
		int i=0,j=0;
		while(i<lenS&&j<lenT){
			while(s[i]!=t[j]&&j<lenT)++j;
			if(j>=lenT)break;
			++i;++j;
		}
		if(i==lenS)printf("YES\n");
		else printf("NO\n");
	}
}
