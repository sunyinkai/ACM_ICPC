#include<bits/stdc++.h>
using namespace std;
//求不相交线段的对数
const int MAXN=5e4+7;
const int INF=1e9+7;

struct line{
	int l,r;
	bool operator<(const line&other)const{
		return l<other.l||(l==other.l&&r<other.r);
	}
}no[MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		int p,r;scanf("%d%d",&p,&r);
		no[i].l=p-r;no[i].r=p+r;
	}
	sort(no,no+N);
	long long ans=0;
	for(int i=0;i<N-1;++i){
		line t;
		t.l=no[i].r+1;t.r=-INF;
		int id=lower_bound(no+i+1,no+N,t)-no;
		ans+=N-id;
	}
	printf("%lld\n",ans);
	return 0;
}
