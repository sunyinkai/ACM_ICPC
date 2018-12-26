#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
int par[MAXN],sum[MAXN];
int find(int x){
	if(par[x]==x)return x;
	int top=find(par[x]);
	sum[x]+=sum[par[x]];
	return par[x]=top;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N,Q;scanf("%d%d",&N,&Q);getchar();
		for(int i=1;i<=N;++i)par[i]=i,sum[i]=0;
		for(int i=0;i<Q;++i){
			char ch;int x,y;
			scanf("%c%d%d",&ch,&x,&y);getchar();
			if(ch=='D'){
				int xx=find(x);
				int yy=find(y);
				if(xx==yy)continue;
				par[xx]=yy;
				//printf("par[%d]=%d\n",xx,par[xx]);
				sum[xx]=sum[y]+sum[x]+1;
				//printf("sum[%d]=%d\n",xx,sum[xx]);
			}else{
				int xx=find(x);
				int yy=find(y);
				if(yy==xx){
					if((sum[x]-sum[y])%2==0){
						printf("In the same gang.\n");
					}else{
						printf("In different gangs.\n");
					}
				}else{
					if(N==2)printf("In different gangs.\n");
					else printf("Not sure yet.\n");
				}
			}
		}
	}
	return 0;
}
