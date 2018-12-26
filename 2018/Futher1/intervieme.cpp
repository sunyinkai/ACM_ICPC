#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=2e5+7;
int f[MAXN][22];
int query(int l,int r){ 
	int k=0;
	while((1<<(k+1))<=r-l+1)++k;
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){ 
	int N,M;
	while(~scanf("%d%d",&N,&M)){ 
		if(N+M<0)break;
		int maxVal=0;
		for(int i=1;i<=N;++i){ 
			scanf("%d",&f[i][0]);
			maxVal=max(maxVal,f[i][0]);
		}
		for(int k=1;(1<<k)<=N;++k){ 
			for(int i=1;i+(1<<k)-1<=N;++i){ 
				f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
			}
		}
		int ans=-1;
		int beg=M/maxVal;if(beg==0)beg=1;
		for(int i=beg;i<=N;++i){ 
			int dis=N/i;
			int val=0;
			for(int j=1;j<=i*dis;j+=dis){ 
				val+=query(j,j+dis-1);
			}
			if(val>M){ 
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
