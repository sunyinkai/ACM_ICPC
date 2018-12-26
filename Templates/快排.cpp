#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
void dfs(int l,int r){
	if(l>=r)return;
	int i=l,j=r;
	int mid=a[(l+r)/2];
	do{
		while(a[i]<mid)++i;
		while(a[j]>mid)--j;
		if(i<=j)swap(a[i],a[j]),++i,--j;
	}while(i<=j);
	dfs(l,j);
	dfs(i,r);
}
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	random_shuffle(a+1,a+N+1);
	dfs(1,N);
	for(int i=1;i<=N;++i)printf(i==1?"%d":" %d",a[i]);
	printf("\n");
	return 0;
}
