#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
int par[MAXN*2];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
void unit(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		par[a]=b;
	}
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N,M;scanf("%d%d",&N,&M);getchar();
		for(int i=1;i<=N*2;++i){
			par[i]=i;
		}
		for(int i=0;i<M;++i){
			char ch=getchar();int a,b;
			scanf("%d%d",&a,&b);getchar();
			if(ch=='D'){
				unit(a,b+N);
				unit(a+N,b);
			}else{
				int x1=find(a),x2=find(a+N);
				int y1=find(b),y2=find(b+N);
				if(x1==y1||x2==y2)printf("In the same gang.\n");
				else if(x1==y2||x2==y1)printf("In different gangs.\n");
				else printf("Not sure yet.\n");
			}
		}
	}
	return 0;
}
