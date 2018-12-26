#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;

int a[MAXN];
int main(){
	int N,K;scanf("%d%d",&N,&K);
	for(int i=0;i<N;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+N);
	int now=0,cnt=0;
	for(int i=0;i<N;++i){
		if(a[i]-now==0)continue;
		printf("%d\n",a[i]-now);
		now=a[i];
		++cnt;
		if(cnt==K)break;
	}

	if(K>cnt){
		for(int i=0;i<K-cnt;++i)
			printf("0\n");
	}
	return 0;
}
