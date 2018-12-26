#include<cstdio>
#include<cstring>
const int MAXN=3e4+7;
int par[MAXN],sum[MAXN];
int find(int x,int t){
	if(par[x]==x)return x;
	int top=find(par[x],t);
	sum[x]+=t;
	return par[x]=top;
}
int main(){
	for(int i=1;i<MAXN;++i)par[i]=i,sum[i]=1;
	int P;scanf("%d",&P);getchar();
	for(int i=0;i<P;++i){
		char ch;ch=getchar();
		if(ch=='M'){
			int a,b;scanf("%d%d",&a,&b);
			int yy=find(b,0);
			find(a,sum[yy]);
		}else{
			int a;scanf("%d",&a);
			printf("%d\n",sum[a]-1);
		}
		getchar();
	}
	return 0;
}
