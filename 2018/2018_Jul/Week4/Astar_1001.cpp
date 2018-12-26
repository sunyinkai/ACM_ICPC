#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1007;
const long long base=1e9+9;
const long long mod=1e7+7;
char s[MAXN][12];
int a[MAXN];
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		int n,m,all;
		scanf("%d%d%d",&n,&m,&all);
		for(int i=0;i<n;++i)
			scanf("%s",s[i]);

		int res=0;
		for(int k=1;k<(1<<m);++k){
			int q[10],top=0;
			for(int i=0;i<m;++i)if(k&(1<<i))q[top++]=i;
			//hash
			for(int i=0;i<n;++i){
				long long val=0;
				for(int j=0;j<top;++j){
					val=(val*base+s[i][q[j]])%mod;
				}
				a[i]=val;
			}
			//sort and count
			sort(a,a+n);
			long long cnt=1,prev=a[0];
			long long sum[MAXN],tot=0;
			for(int i=1;i<n;++i){
				if(a[i]==prev){
					++cnt;
				}
				else{
					sum[tot++]=cnt;
					prev=a[i];
					cnt=1;
				}
			}
			sum[tot++]=cnt;
			/*for(int i=0;i<tot;++i)
				printf("%lld\n",sum[i]);
			printf("\n");*/
			long long ans=0;
			for(int i=0;i<tot;++i){
				for(int j=i+1;j<tot;++j){
					ans+=sum[i]*sum[j];
				}
			}
			if(ans>=all)++res;
		}
		printf("Case #%d: %d\n",test,res);
	}
	return 0;
}
