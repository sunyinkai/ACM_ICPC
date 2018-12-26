#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
const int MAXN=307;
const int INF=1e9+7;
int a[MAXN][MAXN];
int col[MAXN][MAXN];
//O(n^3)求出所有子矩阵的最大值
int main(){
	int N,M,S;scanf("%d%d%d",&N,&M,&S);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			scanf("%d",&a[i][j]);
	for(int j=1;j<=M;++j){
		for(int i=1;i<=N;++i){
			col[j][i]=col[j][i-1]+a[i][j];
		}
	}
	int res=0;
	for(int up=1;up<=N;++up){
		for(int down=up;down<=N;++down){
			int sum=0;
			int prev=0;
			for(int i=1;i<=M;++i){
				sum+=col[i][down]-col[i][up-1];
				int s=(down-up+1)*(i-prev);
				if(s>=S)res=max(res,sum);
				if(sum<0){
					prev=i;
					sum=0;
				}
			}
		}
	}
	printf("%d\n",res);
	return 0;
}
