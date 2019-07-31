//tag: prefix_sum,math
#include<cstdio>
const int MAXN=2e5+7;
int odd[MAXN],even[MAXN];
int a[MAXN];

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
		odd[i]= odd[i-1]+ (i&1?a[i]:0);
		even[i]=even[i-1]+(i&1?0:a[i]);
	}

	int ans=0;
	for(int i=1;i<=N;++i){
		int odd_eat=odd[i-1]+even[N]-even[i];
		int even_eat=even[i-1]+odd[N]-odd[i];
		ans+=(odd_eat==even_eat);
	}
	printf("%d\n",ans);
	return 0;
}
