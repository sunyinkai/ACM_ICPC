#include<cstdio>
#include<cstring>
#include<cstdlib>
const int MAXN=1e6+7;
char t[MAXN];
int ans[MAXN*2];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;char s[2];
		scanf("%d%s",&N,s);
		scanf("%s",t);
		int top=0;
		for(int i=0;i<N;++i){
			int num=abs(s[0]-t[i]);
			int x[2];
			x[0]=num%10;
			x[1]=num/10%10;
			ans[top++]=x[1];ans[top++]=x[0];
		}
		int i=0;
		while(ans[i]==0&&i<top)++i;
		int res=top-i;
		if(res==0)++res;
		printf("%d\n",res);
	}
	return 0;
}
