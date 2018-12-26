#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
map<long long,long long>mp;
int main(){ 
	long long P,B,N;
	while(~scanf("%lld%lld%lld",&P,&B,&N)){ 
		mp.clear();
		long long m=sqrt(P);
		if(m*m!=N)++m;
		long long res=N;
		for(int i=0;i<=m;++i){ 
			mp[res]=i;
			res=res*B%P;
		}

		long long base=1;
		for(int i=0;i<m;++i)base=base*B%P;
		res=base;

		long long ans=-1;
		for(int i=1;i<=m;++i){ 
			if(mp[res]){ 
				ans=i*m-mp[res];
				break;
			}
			res=res*base%P;
		}
		if(ans==-1)printf("no solution\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
