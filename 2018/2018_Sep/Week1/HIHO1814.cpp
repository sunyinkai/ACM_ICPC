//离散化+并查集求连通块个数

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

const int MAXN=1e5+7;
int x[MAXN],y[MAXN];
int q[MAXN*2];
map<int,int>mp;
vector<int>Gx[MAXN],Gy[MAXN];

int par[MAXN*2];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
void unit(int x,int y){
	x=find(x);y=find(y);
	if(x!=y)par[x]=y;
}
int main(){
	int N;scanf("%d",&N);//N个点
	int top=0;
	for(int i=0;i<N;++i){//2*N个下标
		scanf("%d%d",&x[i],&y[i]);
		q[top++]=x[i],q[top++]=y[i];
	}
	sort(q,q+top);
	top=unique(q,q+top)-q;
	for(int i=0;i<top;++i){
		mp[q[i]]=i;
	//	printf("mp[%d]=%d\n",q[i],mp[q[i]]);
	}
	for(int i=0;i<N;++i)par[i]=i;

	for(int i=0;i<N;++i){
		int xx=mp[x[i]],yy=mp[y[i]];
		Gx[xx].push_back(i);
		Gy[yy].push_back(i);
	}
	for(int k=0;k<2*N;++k){
		int len=Gx[k].size();
		if(len>=2)
			for(int i=1;i<len;++i)
				unit(Gx[k][i],Gx[k][i-1]);
		len=Gy[k].size();
		if(len>=2)
			for(int i=1;i<len;++i)
				unit(Gy[k][i],Gy[k][i-1]);
	}
	int ans=N;
	for(int i=0;i<N;++i){
		int x=find(i);
		if(x==i)--ans;
	}
	printf("%d\n",ans);
	return 0;
}
