#include<cstdio>
#include<cstring>
const int MAXN=5000+7;
struct node{
	int xl,xr,yl,yr;
	bool operator <(const node&other)const{
		return xl<other
	}
}a[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d%d%d%d",&a[i].xl,&a[i].yl,&a[i].xr,&a[i].yr);
	}
	return 0;
}
