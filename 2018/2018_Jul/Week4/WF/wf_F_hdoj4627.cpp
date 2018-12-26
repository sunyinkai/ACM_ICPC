#include<cstdio>
#include<cstring>
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		if(n&1){
			printf("%lld\n",(long long)n/2*(n/2+1));
		}else{
			int x=n/2;
			int i;
			for(i=0;i<=n/2;++i){
				if(gcd(x-i,x+i)==1)break;
			}
			printf("%lld\n",(long long)(x-i)*(x+i));
		}
	}
	return 0;
}
