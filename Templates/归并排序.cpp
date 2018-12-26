#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
int a[MAXN],b[MAXN];
void solve(int l,int r){ 
	if(l>=r)return ;
	int m=(l+r)/2;
	solve(l,m);
	solve(m+1,r);
	int i=l,j=m+1,top=l;//假设l与r已经有序了
	while(i<=m&&j<=r){ //归并左边和右边
		if(a[i]<a[j])b[top++]=a[i],++i;
		else b[top++]=a[j],++j;
	}
	while(i<=m)b[top++]=a[i],++i;
	while(j<=r)b[top++]=a[j],++j;
	for(int i=l;i<=r;++i)a[i]=b[i];
	//printf("l:%d,r:%d,m:%d\n",l,r,m);
}
int main(){ 
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	solve(1,N);
	for(int i=1;i<=N;++i)printf("%d ",a[i]);
	printf("\n");
	return 0;
}
