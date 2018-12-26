#include<cstdio>
#include<algorithm>
using namespace std;
int n,K,f[200100],p[100100];
struct node1{int x,y,z,num,tot;}a[100100];
struct node{int x,y,z,t,ans;}A[100100];
bool cmpx(node1 a,node1 b)
{
	if (a.x==b.x&&a.y==b.y) return a.z<b.z;
	if (a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
bool cmpy(node a,node b) { return a.y<b.y;}
int lowbit(int x) { return x&(-x);}
int sum(int x){
	int ans=0;
	for (int i=x;i>=1;i-=lowbit(i)) ans+=f[i];
	return ans;
}
void add(int x,int y){
	for (int i=x;i<=K;i+=lowbit(i)) f[i]+=y;
}

void cdq(int l,int r){
	if (l==r) return;
	int mid=(l+r)/2;
	cdq(l,mid); cdq(mid+1,r);
	sort(A+l,A+mid+1,cmpy);sort(A+mid+1,A+r+1,cmpy);//按y排序
	int i=l,j=mid+1;

	while (j<=r){//左边的修改对右边的询问
		while (i<=mid&&A[i].y<=A[j].y) add(A[i].z,A[i].t),i++;
		A[j].ans+=sum(A[j].z);//对j的贡献
		j++;
	}

	for (int k=l;k<=i-1;k++) add(A[k].z,-A[k].t);//清空数组
}

int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),a[i].num=i;
	sort(a+1,a+n+1,cmpx);
	int tot=1,num=0;
	a[1].tot=1;
	for (int i=2;i<=n+1;i++)
	if (i==n+1||a[i].x!=a[i-1].x||a[i].y!=a[i-1].y||a[i].z!=a[i-1].z)
	{
		A[++num].x=a[i-1].x;A[num].y=a[i-1].y;A[num].z=a[i-1].z;
		A[num].t=tot;
		tot=1;
		a[i-1].tot=num;
	}else tot++,a[i].tot=num+1;
	cdq(1,num);
	for (int i=1;i<=num;i++) p[A[i].ans+A[i].t-1]+=A[i].t;
	for (int i=0;i<n;i++) printf("%d\n",p[i]);
	return 0;
}
