#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef unsigned long long ull;
const ull base =1e9+7;
const int MAXN=1e3+7;
const long long INF=1e15+7;
map<ull,int>mp;
int x[MAXN],y[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d%d",&x[i],&y[i]);
		mp[ x[i]*base+y[i] ]++;
	}
	long long ans=INF;
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			if(mp[x[i]*base+y[j]]&&mp[x[j]*base+y[i]]){
				long long t=(long long)(x[i]-x[j])*(y[i]-y[j]);
				if(t==0)continue;
				if(t<0)t=-t;
				ans=min(ans,t);
			}
		}
	}
	if(ans==INF)printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}
