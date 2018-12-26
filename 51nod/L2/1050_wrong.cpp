#include<cstdio>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int MAXN=1e5+7;
int a[MAXN];
//将环打开?  会有问题-->  4  59 -17 209 -10
int main(){
	//freopen("in.txt","r",stdin);
	int N;scanf("%d",&N);
	long long positive_sum=0;
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
		a[N+i]=a[i];
		if(a[i]>0)positive_sum+=a[i];
	}
	long long ans=0,sum=0;
	if(!positive_sum)ans=0;
	else{
		int id=1;//记录一个id变量,防止跨过整个数组
		for(int i=1;i<=2*N;++i){
			if(sum<0||(i-id==N)){
				sum=0;
				id=i;
			}
			sum+=a[i];
			printf("id:%d,sum:%lld\n",i,sum);
			ans=max(ans,sum);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
