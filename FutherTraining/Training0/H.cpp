#include<cstdio>
#include<cstring>
const int MAXN=21;
int isPrime[40];
void init(){
	memset(isPrime,-1,sizeof(isPrime));
	isPrime[1]=0;
	for(int i=2;i<40;++i){
		if(isPrime[i]){
			for(int j=2*i;j<40;j+=i){
				isPrime[j]=0;
			}
		}
	}
}
int N,a[MAXN],visit[MAXN];
void dfs(int len){
	if(len==N){
		printf("1");
		for(int i=1;i<N;++i)printf(" %d",a[i]);
		printf("\n");
		return;
	}
	for(int i=2;i<=N;++i){
		if(visit[i])continue;
		if(isPrime[i+a[len-1]]){//a[len-1]前一个
			if(len+1==N&&!isPrime[i+1])continue;
			visit[i]=1;
			a[len]=i;
			dfs(len+1);
			visit[i]=0;
		}
	}
}
int main(){
	int test=1;
	init();
	while(~scanf("%d",&N)){
		printf("Case %d:\n",test++);
		a[0]=1;
		if(N%2==0)dfs(1);
		printf("\n");
	}
	return 0;
}
