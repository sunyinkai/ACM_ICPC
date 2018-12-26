#include<cstdio>
#include<cstring>
const int MAXN=1e6+7;
const int MAXM=1e4+7;
char s[MAXN],t[MAXM];
int next[MAXM];
int main(){ 
	int T;scanf("%d",&T);
	while(T--){ 
		scanf("%s%s",t,s);
		int N=strlen(s),M=strlen(t);
		int i=0,j=next[0]=-1;
		while(i<M){ 
			while(j!=-1&&t[i]!=t[j])j=next[j];
			next[++i]=++j;
		}

		int res=0; 
		i=j=0;
		while(i<N&&j<M){ 
			if(j==-1||s[i]==t[j])++i,++j;
			else j=next[j];
			if(j==M){ 
				++res;
				j=next[j];
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
