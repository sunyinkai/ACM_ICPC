//差分
#include<cstdio>
#include<cstring>
const int MAXN=5e5+7;
long long a[MAXN];
int N,M;
int lowbit(int i){
	return i&-i;
}
long long sum(int i){
	long long res=0;
	while(i){
		res+=a[i];
		i-=lowbit(i);
	}
	return res;
}
void add(int i,long long x){
	if(i==0)return ;
	while(i<=N){
		a[i]+=x;
		i+=lowbit(i);
	}
}
int main(){
	scanf("%d%d",&N,&M);
	long long now=0;
	for(int i=1;i<=N;++i){
		long long x;scanf("%lld",&x);
		add(i,x-now);
		now=x;
	}
	for(int i=0;i<M;++i){
		int q;scanf("%d",&q);
		if(q==1){
			int x,y;long long k;
			scanf("%d%d%lld",&x,&y,&k);
			add(x,k);
			add(y+1,-k);
		}else{
			int x;scanf("%d",&x);
			printf("%lld\n",sum(x));
		}
	}
	return 0;
}
