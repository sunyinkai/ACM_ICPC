#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
long long a[MAXN];
long long  N,M;

bool isok(int x){
	long long id=N;
	long long res=0;
	for(int turn=0;;++turn){
		for(int i=1;i<=x;++i){
			if(id==0)break;
			if(a[id]>=turn){
				res+=a[id]-turn;
				--id;
			}else{
				id=0;
				break;
			}
		}
		if(id==0)break;
	}
	return res>=M;
}
int main(){
	scanf("%lld%lld",&N,&M);
	long long sum=0;
	for(int i=1;i<=N;++i){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+N+1);

	if(sum<M){
		printf("-1\n");
	}else{
		int lo=0,hi=N+1;
		while(hi-lo>1){
			int mid=(hi+lo)/2;
			if(isok(mid))hi=mid;
			else lo=mid;
		}
		printf("%d\n",hi);
	}
	return 0;
}
