#include<cstdio>
const int MAXN=1e6+7;
int a[MAXN],b[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i){
		int x;scanf("%d",&x);
		a[x]++;
	}
	long long res=0;
	int prev=0;
	for(int i=(int)1e6;i>=1;--i){
		if(prev){
		//	printf("prev=%d\n",prev);
			if(a[i]+b[i]>=2){
				if(b[i])b[i]=0,a[i]-=1;
				else a[i]-=2;
		//		printf("i=%d,prev=%d\n",i,prev);
				res+=(long long)i*prev;
				prev=0;
			}
		}
		while(a[i]+b[i]>=4){
			if(b[i]==1)b[i]=0,a[i]-=3;
			else a[i]-=4;
			res+=(long long)i*i;
		}//all are i
		if(prev==0){
			if(a[i]+b[i]>=2){
				if(b[i])b[i]=0,a[i]-=1;
				else a[i]-=2;
				prev=i;
			}
		}
		b[i-1]+=a[i];
	}
	printf("%lld\n",res);
	return 0;
}
