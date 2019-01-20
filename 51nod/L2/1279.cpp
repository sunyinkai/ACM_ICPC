#include<bits/stdc++.h>
using namespace std;
const long long INF=1e9+7;
const int MAXN=5e4+7;

int f[MAXN];
int main(){
	int N,M;scanf("%d%d",&N,&M);
	f[0]=INF;
	for(int i=1;i<=N;++i){
		int x;scanf("%d",&x);
		f[i]=min(f[i-1],x);
	}
	f[N+1]=0;

	int down=0,up=N+1;
	int ans=0;
	while(M--){
		int x;scanf("%d",&x);
		int lo=down,hi=up;
		if(hi<=1)continue;
		while(hi-lo>1){
			int mid=(hi+lo)/2;
			if(f[mid]<x)hi=mid;
			else lo=mid;
		}
		if(hi==1){
			if(f[hi]>x)++ans;
		}else ++ans;
		up=hi-1;
	}
	printf("%d\n",ans);
	return 0;
}

