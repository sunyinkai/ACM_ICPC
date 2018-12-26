#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1e9+7;
const int MAXN=1e5+7;
int a[MAXN],x[MAXN],cnt[MAXN];
int num[MAXN];
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		int n;scanf("%d",&n);
		memset(x,0,sizeof(x));
		for(int i=0;i<n;++i)scanf("%d",&x[i]);
		for(int i=n-1;i>=0;--i){
			if(x[i]==0)cnt[i]=cnt[i+1]+1;
			else cnt[i]=cnt[i+1];
		}
		int tot=0;
		for(int i=0;i<n;++i){
			if(x[i]!=0){
				num[tot++]=x[i]+cnt[i];
			}
		}//new
		fill(a,a+n,INF);
		for(int i=0;i<tot;++i){
			int x=num[i];
			int id=lower_bound(a,a+n,x)-a;
			a[id]=x;
		}
		printf("Case #%d: ",test);
		printf("%d\n",lower_bound(a,a+n,INF)-a+cnt[0]);
	}
	return 0;
}

