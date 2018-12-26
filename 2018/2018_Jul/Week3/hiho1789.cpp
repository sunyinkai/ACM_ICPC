#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)

typedef long long LL;
const int MAXN=507;
const long long INF=1e13;
LL q[MAXN],top=0;
LL n,k,num[MAXN];
LL fac[MAXN],cnt[MAXN];

LL solve(LL k){
	LL top=0,res=1;
	while(res<=n){
		q[top++]=res;
		res*=k;
	}
	LL ans=0;
	for(LL i=top-1;i>=1;--i){
		num[i]=n/q[i];
		for(LL j=i+1;j<top;++j){
			num[i]-=num[j];
		}
		ans+=i*num[i];
	}
	return ans;
}


int main(){
	scanf("%lld%lld",&n,&k);
	LL x=k,facCnt=0;
	for(LL i=2;i*i<=x;++i){
		if(x%i==0){
			fac[facCnt]=i;
			while(x%i==0&&x){
				cnt[facCnt]++;
				x/=i;
			}
			facCnt++;
		}
	}
	if(x>1){
		fac[facCnt]=x;
		cnt[facCnt++]=1;
	}

	long long res=INF;
	for(int i=0;i<facCnt;++i){
	//	printf("fac[i]=%lld,cnt[i]=%lld\n",fac[i],cnt[i]);
		LL t=solve(fac[i]);//对每个因子进行计算
		t/=cnt[i];
		res=min(res,t);
	}

	printf("%lld\n",res);
	return 0;
}
