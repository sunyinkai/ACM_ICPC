#include<cstdio>
#include<cstring>
const int MAXN=5e4+7;
long long sum[MAXN];
long long dp[MAXN];
int Q[MAXN];
int N,L;

double Slope(int j,int k){ 
	long long sum1=dp[j]+(long long)(j+sum[j])*(j+sum[j]);

	long long sum2=dp[k]+(long long)(k+sum[k])*(k+sum[k]);
	return (sum1-sum2)*1.0/(j+sum[j]-k-sum[k]);
}


int main(){ 
	scanf("%d%d",&N,&L);
	sum[0]=0;
	for(int i=1;i<=N;++i){ 
		long long x;scanf("%lld",&x);
		sum[i]=sum[i-1]+x;
	}

	++L;
	int left=1,right=1;
	Q[1]=0;
	dp[0]=0;
	for(int i=1;i<=N;++i){ 
		double f=2.0*(i+sum[i]-L);
		while(left<right&&(Slope(Q[left],Q[left+1]))<f)++left;
		int front=Q[left];
		long long t=(i+sum[i]-sum[front]-front-L);
		dp[i]=dp[front]+t*t;//cal
		
		while(left<right&&Slope(Q[right-1],Q[right])>Slope(Q[right],i))
			right--;
		Q[++right]=i;
	}

	printf("%lld\n",dp[N]);
	return 0;
}
