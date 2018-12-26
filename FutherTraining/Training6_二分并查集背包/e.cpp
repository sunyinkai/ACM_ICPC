#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+7;
int a[MAXN];
int L,N,M;
bool isok(int k){
	//printf("k=%d\n",k);
	int step=0;
	for(int i=0;i<N+1;){
		++step;
		int j;
		for(j=i+1;j<=N+1;){
			if(a[j]-a[i]<=k)++j;
			else break;
		}
		j--;
	//	printf("i=%d ,j-1=%d\n",i,j);
		if(j<=i)return false;
		i=j;
	}
	//printf("step=%d\n",step);
	if(step>M)return false;
	else return true;
}
int main(){
	while(~scanf("%d%d%d",&L,&N,&M)){
		a[0]=0;
		for(int i=1;i<=N;++i){
			scanf("%d",&a[i]);
		}
		a[N+1]=L;
		sort(a,a+N+2);
		int lo=0,hi=1e9;
		while(hi-lo>1){
			int mid=(hi+lo)/2;
			if(isok(mid))hi=mid;
			else lo=mid;
		}
		printf("%d\n",hi);
	}
	return 0;
}

