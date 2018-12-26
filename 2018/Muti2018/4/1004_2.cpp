#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int T;scanf("%d",&T);
    long long p[105],ans,cnt;
	for(int i=0;i<T;++i){
		long long N,M;scanf("%lld%lld",&N,&M);
        ans=0;
		for(int i=0;i<N;++i){
			long long a,b;
			scanf("%lld%lld",&a,&b);
			if(M%(a+b)==0)p[i]=M/(a+b)*a;
			else {long long tmp=M%(a+b);tmp-=b;if(tmp<0)tmp=0;p[i]=M/(a+b)*a+tmp;}
		}
        cnt=0;
        sort(p,p+N);
        for(int i=N-1;i>=0;i--)
        {
            ans+=p[i];
            if(ans>M*(N-i-1))cnt++;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
