#include<bits/stdc++.h>
using namespace std;

int N;
long long count_num(int base){
	long long t=base,power=1;
	while(t<=N)t*=base,++power;// two or five

	long long ans=0,sum=0;
	for(;t>=base;t/=base){
		ans+=N/t*power;
		ans-=sum;
		sum+=N/t;
		--power;
	}
	return ans;
}

int main(){
	scanf("%d",&N);
	long long ans=min(count_num(2),count_num(5));
	printf("%lld\n",ans);
	return 0;
}
