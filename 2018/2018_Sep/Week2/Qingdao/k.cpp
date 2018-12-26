#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
const int MAXN=1e5+7;
int a[MAXN];
int cnt[31];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<N;++i){
			int x;scanf("%d",&x);
			for(int i=31;i>=0;--i){
				if(x&(1<<i)){
					cnt[i]++;
					break;
				}
			}
		}
		int res=0;
		for(int i=0;i<=31;++i)res=max(res,cnt[i]);
		printf("%d\n",res);
	}
	return 0;
}

