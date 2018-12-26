#include<cstdio>
const int MAXN=1e6+7;
int a[MAXN];
int q[MAXN],id[MAXN];
int left=1,right=0;
void printQ(){
	printf("\nQ:");
	for(int i=left;i<=right;++i)printf("%d ",q[i]);
	printf("\n");
}
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	q[++right]=a[1];id[right]=1;
	for(int i=2;i<=k;++i){//[left,right];
		while(left<=right&&q[right]>a[i])right--;
		q[++right]=a[i];
		id[right]=i;
	}//第一个窗口
	printQ();
	printf("%d",q[left]);
	for(int i=k+1;i<=n;++i){
		while(left<=right&&q[right]>a[i])right--;
		q[++right]=a[i];id[right]=i;
		printQ();
		if(id[left]+k<=i)left++;//主动出队
		printf(" %d",q[left]);
	}
	printf("\n");
	return 0;
}
