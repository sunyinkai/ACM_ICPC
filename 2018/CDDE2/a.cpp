#include<cstdio>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

const int MAXN=1e5+7;
char s[MAXN];
int sum[MAXN];
//二分长度，check是否满足
int N,K;
bool isok(int x){
	//printf("x=%d\n",x);
	for(int i=1;i<=N;++i){
		if(s[i]!='0')continue;
		int l=i-x;l=max(1,l);
		int r=i+x;r=min(r,N);
	//	printf("l=%d,r=%d\n",l,r);
		int x=sum[r]-sum[l-1];
		if(x>=K)return true;
	}
	return false;
}
int main(){
	scanf("%d%d",&N,&K);
	++K;
	scanf("%s",s+1);
	for(int i=1;i<=N;++i){
		sum[i]=sum[i-1]+(s[i]=='0');
	}
	int lo=0,hi=N;
	while(hi-lo>1){
		int mid=(hi+lo)/2;
		if(isok(mid))hi=mid;
		else lo=mid;
	}
	printf("%d\n",hi);
	return 0;
}
