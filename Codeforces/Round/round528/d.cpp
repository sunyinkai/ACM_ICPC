#include<cstdio>
const int MAXN=1e5+7;
int du[MAXN];
int main(){
	int N,S;scanf("%d%d",&N,&S);
	for(int i=1;i<N;++i){
		int x,y;scanf("%d%d",&x,&y);
		du[x]++;du[y]++;
	}
	int cnt=0;
	for(int i=1;i<=N;++i)
		if(du[i]==1)++cnt;
	printf("%.10f\n",2.0*S/cnt);
	return 0;
}
