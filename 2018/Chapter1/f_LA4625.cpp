#include<cstdio>
#include<cstring>
const int MAXN=5007;
int l[MAXN],r[MAXN];
int N;

bool isok(int x){
	int lx=0,rx=0;
	
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;++i)scanf("%d%d",&l[i],&r[i]);
		int lo=-1,hi=N+1;
		while(hi-lo>1){
			int mid=(hi+lo)/2;
			if(isok(mid))hi=mid;
			else lo=mid;
		}
		printf("%d\n",hi);
	}
	return 0;
}
