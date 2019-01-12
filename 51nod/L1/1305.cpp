#include<cstdio>
int main(){
	int N;scanf("%d",&N);
	int count_1=0,count_2=0;
	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		if(x==1)count_1++;
		else if(x==2)count_2++;
	}
	long long ans=(long long)count_1*(count_1-1)/2*2;
	ans+=(long long)count_1*(N-count_1);
	ans+=(long long)count_2*(count_2-1)/2;
	printf("%lld\n",ans);
	return 0;
}
