#include<bits/stdc++.h>
using namespace std;
const int MAXM=1e6+7;
const int MAXN=1e5+7;
const int INF=1e9+7;
int cnt[MAXM],cost[MAXM];
void up(int n,int k){
	if(!n)return ;
	while(n<MAXM){
		cnt[n]++;
		cost[n]+=k;
		k++;
		n<<=1;
	}
}

int main(){
	int N;scanf("%d",&N);

	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		int step=0;
		up(2*x,1);
		while(x){
			if(x&1)up(x/2*2,step+2);
			cnt[x]++;
			cost[x]+=step;
			x/=2;
			step++;
		}
		cnt[0]++;cost[0]+=step;
	}

	int ans=INF;
	for(int i=0;i<MAXM;++i){
		if(cnt[i]==N){
			ans=min(ans,cost[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
