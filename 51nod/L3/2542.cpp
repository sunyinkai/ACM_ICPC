//tag: greedy,binary_search
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=107;
int a[MAXN];
int N,M;

bool isok(int x){
	int b[MAXN];
	int sum=0;
	int top=1;
	int dec=0;
	while(top!=N+1){
		for(int i=1;i<=x;++i){
			if(top==N+1)break;
			if(a[top]>dec)sum+=a[top++]-dec;
			else ++top;
		}
		++dec;
	}
	return sum>=M;
}

int main(){
	scanf("%d%d",&N,&M);
	int sum=0;
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum<M){
		printf("-1\n");
		return 0;
	}
	auto cmp= [](int x,int y){
		return x>y;
	};
	sort(a+1,a+N+1,cmp);
	int lo=0,hi=N+1;
	while(hi-lo>1){
		int mid=(hi+lo)/2;
		if(isok(mid))hi=mid;
		else lo=mid;
	}
	printf("%d\n",hi);
}
