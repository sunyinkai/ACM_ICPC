#include<cstdio>
#include<cstring>
const int MAXN=1e7+7;
int isPrim[MAXN];
int N;
void init(){
	memset(isPrim,-1,sizeof(isPrim));
	isPrim[1]=0;
	for(int i=2;i<=N;++i){
		if(isPrim[i]){
			for(int j=2*i;j<=N;j+=i)isPrim[j]=0;
		}
	}
}
int main(){
	int Q;
	scanf("%d%d",&N,&Q);
	init();
	while(Q--){
		int a;scanf("%d",&a);
		printf(isPrim[a]?"Yes\n":"No\n");
	}
	return 0;
}
