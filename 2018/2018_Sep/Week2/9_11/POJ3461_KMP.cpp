#include<cstdio>
#include<cstring>

const int MAXN=1e4+7;
const int MAXM=1e6+7;
char s[MAXN],t[MAXM];
int next[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s%s",s,t);
		//next
		int N=strlen(s);
		int i=0,j=next[i]=-1;
		while(i<N){
			while(j!=-1&&s[i]!=s[j])j=next[j];
			next[++i]=++j;
		}

		int M=strlen(t);
		int ans=0;
		for(i=j=0;i<M;){
			if(j==-1||s[j]==t[i])++i,++j;
			else j=next[j];

			if(j==N){
				++ans;
				j=next[j];
				//j=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
