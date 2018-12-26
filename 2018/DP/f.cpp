#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

const int MAXN=37;
const int INF=1e9+7;
struct node{
	int w,h;
	node(int x,int y):w(x),h(y){}
	bool operator<(const node&other)const{
		return w<other.w||(w==other.w&&h<other.h);
	}
};
map<node,int>mp;
int x[MAXN],y[MAXN],z[MAXN];//x<=y<=z;
int N;

int dfs(int w,int h){//w<=h
	if(mp[node(w,h)])return mp[node(w,h)];
	int res=0;
	for(int i=0;i<N;++i){
		if(x[i]<w&&y[i]<h)res=max(res,dfs(x[i],y[i])+z[i]);
		if(x[i]<w&&z[i]<h)res=max(res,dfs(x[i],z[i])+y[i]);
		if(y[i]<w&&z[i]<h)res=max(res,dfs(y[i],z[i])+x[i]);
	}
	return mp[node(w,h)]=res;
}
int main(){
	int test=1;
	while(~scanf("%d",&N)&&N){
		mp.clear();
		int a[3];
		for(int i=0;i<N;++i){
			for(int j=0;j<3;++j)scanf("%d",&a[j]);
			sort(a,a+3);
			x[i]=a[0];y[i]=a[1];z[i]=a[2];
		}
		printf("Case %d: maximum height = %d\n",test,dfs(INF,INF));
		++test;
	}
	return 0;
}
