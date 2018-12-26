#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e4+7;
const int MAXM=1e6+7;
int a[MAXN];
int q[MAXM];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=1;i<=N;++i){
			int x;scanf("%d",&x);
			a[x]++;
		}
		int top=0;
		for(int i=1;i<MAXN;++i){
			while(a[i]>=2){
				q[top++]=i;
				a[i]-=2;
			}
			a[i]=0;
		}
		double res=1e9+7;
		int x,y;
		for(int i=1;i<top;++i){
			if((double)1.0*(q[i]+q[i-1])*(q[i]+q[i-1])/(q[i]*q[i-1]*1.0)<res){
				x=q[i],y=q[i-1];
				res=(double)1.0*(q[i]+q[i-1])*(q[i]+q[i-1])/(q[i]*q[i-1]*1.0);
			}
		}
		printf("%d %d %d %d\n",x,x,y,y);
	}
	return 0;
}
