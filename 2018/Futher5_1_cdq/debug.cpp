#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100005
#define MAXK 200005
using namespace std;

int n,k,ans[MAXN];
struct Ope {
	int x,y,z,cnt,ans;
	//点的坐标,个数,以及答案
}ope[MAXN],ope2[MAXN];
int c[MAXK];
void update(int x,int a) {
	while(x<=k) {
		c[x]+=a;
		x+=(x&(-x));
	}
}
int query(int x) {
	int res=0;
	while(x) {
		res+=c[x];
		x-=(x&(-x));
	}
	return res;
}
bool cmp(Ope a,Ope b) {
	if(a.x==b.x) {
		if(a.y==b.y) return a.z<b.z;
		return a.y<b.y;
	}
	return a.x<b.x;
}
bool cmp2(Ope a,Ope b) {
	if(a.y==b.y) return a.z<b.z;
	return a.y<b.y;
}

void CDQ(int l,int r) {
	if(l==r) return;
	int mid=(l+r)/2;
	CDQ(l,mid);CDQ(mid+1,r);
	sort(ope2+l,ope2+mid+1,cmp2);//按y排序
	sort(ope2+mid+1,ope2+r+1,cmp2);
	int i=l,j=mid+1;
	while(j<=r){
		while(i<=mid && ope2[i].y<=ope2[j].y) update(ope2[i].z,ope2[i].cnt),++i;
		ope2[j].ans+=query(ope2[j].z);
		++j;
	}
	for(j=l;j<i;j++) update(ope2[j].z,-ope2[j].cnt);
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){ 
		scanf("%d%d%d",&ope[i].x,&ope[i].y,&ope[i].z);
	} 
	sort(ope+1,ope+1+n,cmp);//按x排序
	int cnt=0,num=0;
	for(int i=1;i<=n;i++) {//处理重复
		num++;
		if(ope[i].x==ope[i+1].x && ope[i].y==ope[i+1].y && ope[i].z==ope[i+1].z) continue;
		else {
			ope2[++cnt]=ope[i];
			ope2[cnt].cnt=num;
			num=0;
		}
	}
	CDQ(1,cnt);
	for(int i=1;i<=cnt;i++) ans[ope2[i].ans+ope2[i].cnt]+=ope2[i].cnt;
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
