#include<bits/stdc++.h>
using namespace std;

int main(){
	long long C,Hr,Hb,Wr,Wb;
	scanf("%lld%lld%lld%lld%lld",&C,&Hr,&Hb,&Wr,&Wb);
	int cnt=sqrt(C)+1;
	long long ans=0;
	for(int i=0;i<=cnt;++i){
		long long t=0,k=0;
		if(Wr*i<=C)
			t=Hr*i+(C-Wr*i)/Wb*Hb;//i 个a物品
		if(Wb*i<=C)
		    k=Hb*i+(C-Wb*i)/Wr*Hr;//i 个b物品
		ans=max(ans,t);
		ans=max(ans,k);
	}
	printf("%lld\n",ans);
	return 0;
}
