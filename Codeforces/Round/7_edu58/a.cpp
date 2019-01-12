#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;scanf("%d",&q);
	while(q--){
		long long l,r,x;scanf("%lld%lld%lld",&l,&r,&x);
		if(l>x){
			printf("%lld\n",x);
		}else{
			long long big=r/x;
			++big;
		//	printf("big:%lld\n",big);
			printf("%lld\n",big*x);
		}
	}
	return 0;
}
