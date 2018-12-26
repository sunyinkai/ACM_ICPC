//返回第一个匹配的位置

#include<cstdio>
#include<cstring>
const int MAXN=1e6+7;
const int MAXM=1e4+7;

int a[MAXN],b[MAXM];
int next[MAXM];
int main(){ 
	int T;scanf("%d",&T);
	while(T--){ 
		int N,M;scanf("%d%d",&N,&M);
		for(int i=0;i<N;++i)scanf("%d",&a[i]);
		for(int j=0;j<M;++j)scanf("%d",&b[j]);

		int i=0,j=next[0]=-1;
		while(i<M){ 
			while(j!=-1&&b[i]!=b[j])j=next[j];
			next[++i]=++j;
		}//next
		int res=0;
		i=j=0;
		int tag=1;
		while(i<N&&j<M){ 
			if(j==-1||a[i]==b[j])++i,++j;
			else j=next[j];
			if(j==M){ 
				//j=next[j];//可重复
				//++res;
				tag=0;
				break;
			}
		}
		if(tag)printf("-1\n");
		else printf("%d\n",i-M+1);
	}
	return 0;
}
