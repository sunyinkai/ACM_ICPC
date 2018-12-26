#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;
const int MAXN=1e5+7;
const long long mod=1e9+7;
int a[MAXN];
int par[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
vector<int>G[MAXN];
int mp[MAXN];
int cnt[31],q[MAXN],val[31];
int main(){
	int T;scanf("%d",&T);
	val[0]=1;
	for(int i=1;i<=30;++i)val[i]=val[i-1]*2;

	while(T--){
		int N,M;scanf("%d%d",&N,&M);
		for(int i=1;i<=N;++i)G[i].clear();
		for(int i=1;i<=N;++i)mp[i]=0;
		for(int i=1;i<=N;++i)scanf("%d",&a[i]),par[i]=i;
		for(int i=0;i<M;++i){
			int a,b;scanf("%d%d",&a,&b);
			a=find(a);b=find(b);
			if(a!=b)par[a]=b;
		}
		int now=1;
		for(int i=1;i<=N;++i){
			int x=find(par[i]);
			if(!mp[x]){
				mp[x]=now++;
			}	
			G[mp[x]].push_back(i);
		}

		long long res=0;
		for(int i=1;i<now;++i){
			int len=G[i].size();
			if(len==1)continue;
			memset(cnt,0,sizeof(cnt));
			for(int j=0;j<len;++j){
				int x=a[G[i][j]];
				q[j]=x;
				for(int k=0;k<=30;++k){
					cnt[k]+=x%2;
					x/=2;
				}
			}

			sort(q,q+len);
			for(int j=len-1;j>=0;--j){
				int num=q[j];
				for(int k=0;k<=30;++k){
					int x=num%2;
					num/=2;
					if(x&1){
						cnt[k]--;
						res=(res+(long long)val[k]*cnt[k]%mod*q[j])%mod;
					}
				}
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
