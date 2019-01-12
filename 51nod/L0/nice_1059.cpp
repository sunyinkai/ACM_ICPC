#include<cstdio>
const int MAXN=1e5+7;
int a[MAXN];
const long long mod=1e9;

int main(){
	int N;scanf("%d",&N);
	int len=0;
	a[0]=1;
	while(N>1){
		int add=0;
		for(int i=0;i<=len;++i){
			long long ans=(long long)a[i]*N+add;
			add=ans/mod;
			a[i]=ans%mod;
		}
		if(add)a[++len]=add;
		N--;
	}
	printf("%d",a[len]);
	while(len--)printf("%09d",a[len]);
	printf("\n");
	return 0;
}
