#include<cstdio>
#include<algorithm>
using namespace std;
void swap(int *x,int *y){
	int tmp=*x;
	*x=*y;
	*y=tmp;
}
const int MAXN=1e6+7;
int a[MAXN];
int dfs(int l,int r,int k){
	int i=l,j=r;
	while(i<j){//1,2,3,4,5,6,7,8,会卡这个东西,shuffle
		while(a[j]>=a[l]&&i<j)j--;	//必须从右边开始找
		while(a[i]<=a[l]&&i<j)i++;
		swap(&a[i],&a[j]);
	}
	swap(&a[i],&a[l]);
	if(k==i-l+1)return a[i];
	else if(k>i-l+1)return dfs(i+1,r,k-(i-l+1));
	else return dfs(l,i-1,k);
}
int main(){
	int N;
	while(~scanf("%d",&N)){
		for(int i=1;i<=N;++i)scanf("%d",&a[i]);
		random_shuffle(a+1,a+N+1);
		int K=(N+1)/2;
		printf("%d\n",dfs(1,N,K));
	}
	return 0;
}
