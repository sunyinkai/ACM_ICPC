#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int dfs(int l,int r){
	if(l>=r)return 0;
	int m=(l+r)/2;
	int res=0;
	res+=dfs(l,m-1)+dfs(m+1,r);
	int add=0;
	for(int id=l;id<=m-1;++id) if(a[id]>a[m])++res,++add;
	for(int id=m+1;id<=r;++id) if(a[id]<a[m])++res,++add;
	int t[MAXN];
	int i=l,j=m+1,tot=1;
	while(i<=m-1&&j<=r){
		while(i<=m-1&&a[i]<=a[j]){
			t[tot]=a[i++];
			tot++;
		}
		while(j<=r&&a[j]<a[i]){
			t[tot]=a[j++];
			tot++;
			res+=m-i;
		}
	}
	while(i<=m-1)t[tot]=a[i++],tot++;
	while(j<=r)t[tot]=a[j++],tot++;
	t[tot++]=a[m];
	for(int id=tot-2;id>=1;--id){
		if(t[id]>t[id+1])swap(t[id],t[id+1]);
	}
	for(int id=l;id<=r;++id)a[id]=t[id-l+1];
	return res;
}
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	printf("%d\n",dfs(1,N));
	return 0;
}
