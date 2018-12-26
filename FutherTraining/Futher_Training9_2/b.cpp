#include<cstdio>
#include<cmath>
#include<cstring>
#define min(a,b) (a<b?a:b)
const int MAXN=1e5+7;
int a[MAXN];
int bit[MAXN];
int N;
int lowbit(int x){
	return x&-x;
}
int sum(int x){
	int res=0;
	while(x){
		res+=bit[x];
		x-=lowbit(x);
	}
	return res;
}
void add(int i,int x){
	while(i<=N){
		bit[i]+=x;
		i+=lowbit(i);
	}
}
int f[MAXN];//f[i]:有多少个数比a[i]小
int right[MAXN],left[MAXN];
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		memset(bit,0,sizeof(bit));
		memset(f,0,sizeof(f));

		scanf("%d",&N);
		for(int i=1;i<=N;++i){
			scanf("%d",&a[i]);
			left[a[i]]=min(a[i],i);
		}
		printf("Case #%d:",test);
		for(int i=N;i>=1;--i){
			f[i]=sum(a[i]);
			right[a[i]]=i+f[i];
	//		printf("right[%d]=%d\n",a[i],right[a[i]]);
			add(a[i],1);
		}
		for(int i=1;i<=N;++i){
			printf(" %d",right[i]-left[i]);
		}
		printf("\n");
	}
	return 0;
}
