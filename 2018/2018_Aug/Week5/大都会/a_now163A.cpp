#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<unordered_map>
#define eps 1e-6
using namespace std;
unordered_map<int,int>mp;
const int MAXN=1e4+7;
int x[MAXN],y[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;double p;
		scanf("%d%lf",&N,&p);
		mp.clear();
		for(int i=0;i<N;++i){
			scanf("%d%d",&x[i],&y[i]);
			mp[x[i]]++;
		}
		bool hasAns=false;
		for(auto it=mp.begin();it!=mp.end();++it){
			if(it->second*1.0/N>=p){
				hasAns=true;
			}
		}

		srand(time(NULL));
		for(int id=0;id<500;++id){
			int a=rand()%N;
			int b;
			while((b=(rand()%N))==a||x[a]==x[b]);
			double k=(y[a]-y[b])*1.0/(x[a]-x[b]);
			int res=1;
			for(int i=0;i<N;++i){
				if(i==a||x[i]==x[a])continue;
				double k2=(y[i]-y[a])*1.0/(x[i]-x[a]);
				//printf("k2=%.2f\n",k2);
				if(fabs(k2-k)<eps)++res;
			}
		//	printf("k=%.2f,res=%d\n",k,res);
			if(res*1.0/N>=p)hasAns=true;
		}
		if(hasAns)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
