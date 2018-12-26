#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=1007;
const double INF=1e9+7;
int x[MAXN],y[MAXN],p[MAXN];
struct edge{
	int u,v;double c;
	bool operator <(const edge&other)const{
		return c<other.c;
	}
}es[MAXN*MAXN],e[MAXN];
int par[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
double dis(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=1;i<=N;++i)scanf("%d%d%d",&x[i],&y[i],&p[i]);
		int tot=0;
		for(int i=1;i<=N;++i){
			for(int j=i+1;j<=N;++j){
				es[tot].u=i;es[tot].v=j;
				es[tot++].c=dis(x[i],y[i],x[j],y[j]);
			}
		}
		sort(es,es+tot);
		int cnt=0;//最小生成树的长度
		double res=0.0;
		for(int i=1;i<=N;++i)par[i]=i;
		for(int i=0;i<tot;++i){
			int u=es[i].u,v=es[i].v;
			int x=find(u),y=find(v);
			if(x!=y){
				par[x]=y;
				e[cnt++]=es[i];
				res+=es[i].c;
			}
		}
		double ans=0.0;
		for(int i=0;i<tot;++i){//枚举边
			for(int j=1;j<=N;++j)par[j]=j;

			edge tmp[MAXN];
			for(int i=0;i<cnt;++i)
				tmp[i]=e[i];
			tmp[cnt++]=e[i];

			int x=es[i].u,y=es[i].v;
			par[x]=y;

			double fenzi=p[es[i].u]+p[es[i].v];
			double fenmu=0.0;
			sort(tmp,tmp+cnt);
			for(int j=0;j<cnt;++j){
				int x=tmp[j].u,y=tmp[j].v;
				x=find(x);y=find(y);
				if(x!=y){
					par[x]=y;
					fenmu+=tmp[j].c;
				}
			}
			--cnt;
			ans=max(ans,fenzi/fenmu);
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
