#include<cstdio>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
const int MAXN=1007;
const long long mod=1e9+7;
long long fast_pow(long long base ,long long n){
	long long res=1;
	while(n){
		if(n&1)res=res*base%mod;
		base=base*base%mod;
		n/=2;
	}
	return res;
}
struct node{
	int x,y;
	bool operator<(const node&other)const{
		return x<other.x||(x==other.x&&y<other.y);
	}
}a[MAXN];
int q[MAXN],tot;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		map<node,int>mp;
		mp.clear();
		for(int i=1;i<=N;++i){
			scanf("%d%d",&a[i].x,&a[i].y);
			mp[a[i]]++;
		}
		tot=0;
		for(auto it=mp.begin();it!=mp.end();++it){
			q[tot++]=it->second;
		}
		long long res=0;
		for(int i=0;i<tot;++i){
			int cnt=q[i];
			res=(res+fast_pow(2,cnt)-cnt-1+mod)%mod;
		}
		for(int i=0;i<tot;++i){
			for(int j=0;j<tot;++j){
				if(j==i)continue;
				int cntx=q[i],cnty=q[j];
				long long tmp=(fast_pow(2,cntx)-1+mod)%mod;
				long long tmp2=(fast_pow(2,cnty)-1+mod)%mod;
				res=(res+tmp*tmp2%mod)%mod;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
