#include<cstdio>
int main(){
	long long n;scanf("%lld",&n);
	long long num=0;
	for(;;){
		if(num*10+9>n)break;
		num=num*10+9;
	}
	long long y=n-num;
	int ans=0;
	while(num){
		ans+=num%10;
		num/=10;
	}
	while(y){
		ans+=y%10;
		y/=10;
	}
	printf("%d\n",ans);
	return 0;
}
