#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int x[MAXN],block;
struct node{
	int l,r;
	int id,res;
	bool operator<(const node&other)const {
		if(l/block!=other.l/block)return l/block<other.l/block;
		else{
			return r<other.r;
		} 
	}
}a[MAXN];

int cnt[MAXN*2];
int main(){
	int N;
	while(~scanf("%d",&N)&&N){
		int q;scanf("%d",&q);
		block=sqrt(N);
		for(int i=1;i<=N;++i)scanf("%d",&x[i]),x[i]+=(int)2e5;
		for(int i=0;i<q;++i){
			scanf("%d%d",&a[i].l,&a[i].r);
			a[i].id=i;
		}
		sort(a,a+q);
		/*for(int i=0;i<q;++i){
			printf("%d %d\n",a[i].l,a[i].r);
		}*/
		//莫队
		int lo=1,hi=1;
		for(int i=0;i<q;++i){
			int L=a[i].l,R=a[i].r;
			while(lo<L){cnt[x[lo]]--;lo++;}
			while(lo>L){--lo;cnt[x[lo]]++;}//增加和减少不一样
			while(hi<R){++hi;cnt[x[hi]]++;}
			while(hi>R){cnt[x[hi]]--;hi--;}
			
		}
	}
	return 0;
}
