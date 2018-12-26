#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+7;
const long long INF=1e10+7;
typedef long long ll;

//二分最大边,跑最大生成树
struct node{
	ll a,b,c;
	bool operator<(const node&other)const{
		return c>other.c;
	}
}no[MAXN];
int N,M;
int par[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
void unit(int x,int y){
	x=find(x);y=find(y);
	if(x!=y)par[x]=y;
}

bool isok(long long &val,long long mid){
	for(int i=1;i<=N;++i)par[i]=i;
	int cnt=0;
	for(int i=0;i<M;++i){
		if(no[i].c>mid)continue;
		int x=find(no[i].a);
		int y=find(no[i].b);
		if(x!=y){
			par[x]=y;
			++cnt;
			val+=no[i].c;
		}
	}
	return cnt==N-1;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i){
		scanf("%lld%lld%lld",&no[i].a,&no[i].b,&no[i].c);
	}
	sort(no,no+M);
	long long lo=-INF,hi=INF;
	long long ans=-INF;
	while(hi-lo>1){
		long long mid=(hi+lo)/2;
		long long val=0;
		if(isok(val,mid)){
			hi=mid;
			ans=val;
		}
		else lo=mid;
	}
	printf("%lld\n",ans);
	return 0;
}
