#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int block=sqrt(1e5); 
const int MAXN=1e5+7;
const long long mod=1e9+7;
struct node{
	int l,r,id;
	long long val;
	bool operator<(const node&other)const{
		if(l/block<other.block)return true;
		else return r<other.r;
	}
}no[MAXN];
long long ans[MAXN];
int main(){
	int T;scanf("%d",&T);
	for(int i=0;i<T;++i){
		scanf("%d%d",&no[i].l,&no[i].r);
		no[i].id=i;
	}
	sort(no,no+T);
	int l=1,r=1;
	long long val=1;

	for(int i=0;i<T;++i){
	
	}
	for(int i=0;i<T;++i)
		printf("%lld ",ans[i]);
	return 0;
}
