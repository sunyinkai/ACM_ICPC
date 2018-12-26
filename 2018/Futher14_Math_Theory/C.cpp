#include<cstdio>
#include<cstring>
// \sigma n/i 
int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		long long sum=0;
		if(n>k){
			sum+=(long long)k*(n-k);
			n=k;
		}
		int l,r=n,val;
		for(;;){
			val=k/r;
			l=k/(val+1)+1;
		//	printf("left=%d,right=%d,val=%d\n",l,r,val);
			sum+=((long long)k%l+(long long)k%r)*(r-l+1)/2;
		//	printf("l:%d,r:%d\n",k%l,k%r);
			if(val==k)break;
			r=k/(val+1);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
