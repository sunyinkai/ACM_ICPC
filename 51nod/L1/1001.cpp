#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=5e4+7;
int a[MAXN];
//双指针
//O(nlogn)排序，O(n)求a[i]+a[j]==K

int main(){
	int K,N;scanf("%d%d",&K,&N);
	for(int i=0;i<N;++i)
		scanf("%d",&a[i]);
	sort(a,a+N);
	int i=0,j=N-1;
	bool hasAns=false;
	while(i<j){
		if(a[i]+a[j]<K)++i;
		else if(a[i]+a[j]>K)--j;
		else{
			 printf("%d %d\n",a[i],a[j]);
			 ++i;--j;
			 hasAns=true;
		}
	}
	if(!hasAns)printf("No solution\n");

	return 0;
}