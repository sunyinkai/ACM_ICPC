#include<cstdio>
const int MAXN=1e5+7;
const long long mod=1e9+7;
int N,Q;


struct BIT{
	long long bit[MAXN];
	int lowbit(int i){return i&-i;}

	void add(int p,long long  x){
		for(int i=p;i<=N;i+=lowbit(i)){
			bit[i]+=x;
		}
	}

	long long sum(int p){
		long long ans=0;
		for(int i=p;i;i-=lowbit(i))ans+=bit[i];
		return ans;
	}
}a,b;

int main(){
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;++i){
		long long x;scanf("%lld",&x);
		a.add(i,x);
		b.add(i,i*x);
	}

	while(Q--){
		int q;scanf("%d",&q);
		if(q==1){
			long long l,r;scanf("%lld%lld",&l,&r);
			long long ans=(r+1)*(a.sum(r)-a.sum(l-1))-(b.sum(r)-b.sum(l-1));
			printf("%lld\n",ans);
		}else{
			int p;long long x;
			scanf("%d%lld",&p,&x);
			long long val=a.sum(p)-a.sum(p-1);
			a.add(p,x-val);
			b.add(p,(x-val)*p);
		}
	}

	return 0;
}
