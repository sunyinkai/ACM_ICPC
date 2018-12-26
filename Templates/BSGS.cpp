#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
map<long long ,long long>mp;
int main(){ 
	long long P,B,N;
	while(~scanf("%lld%lld%lld",&P,&B,&N)){ 
		mp.clear();
		long long m=sqrt(P);
		if(m*m!=P)++m;
		long long base=1;
		for(int j=0;j<=m;++j){ 
			long long res=N*base%P;
			mp[res]=j;
			if(j==m)break;//为了得到base^m
			base=base*B%P;
		}
		long long res=1;
		long long ans=-1;
		for(int i=1;i<=m;++i){ 
			res=res*base%P;
			if(mp[res]){ 
				ans=i*m-mp[res];
				break;
			}
		}
		if(ans==-1)printf("no solution\n");
		else printf("%lld\n",ans);
	}
	
	return 0;
}
