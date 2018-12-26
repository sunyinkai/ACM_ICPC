#include<cstdio>
#include<cstring>
const int MAXN=1e6+7;
int next[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		char s[MAXN];
		scanf("%s",s);
		int len=strlen(s);
		int i=0,j=next[i]=-1;

		while(i<len){
			while(j!=-1&&s[i]!=s[j])j=next[j];
			next[++i]=++j;
		}

		int x=len-next[len];
		printf("len=%d,next[len]=%d,x=%d\n",len,next[len],x);
		if(len%x)printf("%d\n",x);
		else printf("%d\n",0);

	}
	return 0;
}
