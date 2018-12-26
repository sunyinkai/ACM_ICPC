#include<cstdio>
#include<cstring>
const int MAXN=107;
char s[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		scanf("%s",s);
		bool hasAns=true;
		for(int i=0,j=N-1;i<j;++i,--j){
			if(s[i]==s[j])continue;
			int x=s[i]+1,y=s[i]-1;
			int xx=s[j]+1,yy=s[j]-1;
			if(x==yy||xx==y)continue;
			hasAns=false;
		}
		if(hasAns)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
