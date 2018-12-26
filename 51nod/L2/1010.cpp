#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
const long long INF=1e18+1e10;
long long a[30];
int top=0;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		long long x;scanf("%lld",&x);
		long long ans=INF;
		__int128 val=1;

		for(int i=0;i<63;++i){//2^a
			__int128 t=val;
			if(t>=x){ans=min(ans,t);break;}

			for(int j=0;j<63;++j){//3^b
				if(t>=x){ans=min(ans,t);break;}

				__int128 last=t;
				for(int k=0;k<63;++k){
					if(last>=x){ans=min(ans,last);break;}
					last*=5;
				}
				t*=3;
			}
			val*=2;
		}
		printf("%lld\n",max(ans,2));
	}
	return 0;
}
