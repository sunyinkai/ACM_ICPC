//画一个圆，使得圆上与圆内点的权值和最大
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e5+7;
struct node{
	long long dis,val;
	bool operator<(const node&other)const{
		return dis<other.dis;
	}
}no[MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		long long x,y;
		scanf("%lld%lld%lld",&x,&y,&no[i].val);
		no[i].dis=x*x+y*y;	
	}
	sort(no,no+N);
	long long res=0,t=0;
	int i=0;
	if(no[0].dis==0)res=no[0].val,t=no[0].val,++i;
	for(;i<N;++i){
		t=t+no[i].val;
		res=max(res,t);
	}
	printf("%lld\n",res);
	return 0;
}
