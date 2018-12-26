#include<cstdio>
#include<cstring>
#include<cmath>

const int MAXN=1e5+7;
long long power[50];
void init(){ 
	power[0]=1;
	for(int i=1;i<40;++i)
		power[i]=(long long)power[i-1]*2;
}

long long sum[MAXN];

inline int read(){ 
	char ch;
	int res=0;
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res;
}
int main(){ 
	init();
	int T;scanf("%d",&T);
	while(T--){ 
		int N;scanf("%d",&N);getchar();
		for(int i=1;i<=N;++i)sum[i]=0;
		for(int i=1;i<=N;++i){ 
			int x=read();
			sum[i]=sum[i-1]+x;
		}

		sum[N+1]=sum[N];
		long long res=0;
		for(int i=1;i<=N;++i){ 
			int prev=i;
			int up;
			if(sum[N]-sum[i-1]!=0) up=(int)log2(sum[N]-sum[i-1])+1;
			else  up=34;
			for(int k=1;k<=up;++k){ 
				int lo=prev-1,hi=N+1;
				while(hi-lo>1){ 
					int mid=(hi+lo)/2;
					if(sum[mid]-sum[i-1]>=power[k])hi=mid;
					else lo=mid;
				}

				long long cnt=hi-1 -prev +1;
				res+=k*(i*cnt+(hi-1+prev)*(hi-prev)/2);
				if(hi==N+1)break;
				prev=hi;
			}
		}

		printf("%lld\n",res);
	}
	return 0;
}
