#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
char s[MAXN];
int sum[MAXN][26];
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		int n,q;scanf("%d%d",&n,&q);
		scanf("%s",s);
		for(int i=0;i<26;++i)sum[0][i]=0;
		for(int i=0;i<n;++i){
			int x=s[i]-'A';
			for(int j=0;j<26;++j){
				if(j==x)sum[i+1][j]=sum[i][j]+1;
				else sum[i+1][j]=sum[i][j];
			}
		}//init();
		printf("Case #%d:\n",test);
		while(q--){
			int  l,r;scanf("%d%d",&l,&r);
			int i;
			for(i=0;i<26;++i){
				if(sum[r][i]-sum[l-1][i])break;
			}
			printf("%d\n",sum[r][i]-sum[l-1][i]);
		}
	}
	return 0;
}
