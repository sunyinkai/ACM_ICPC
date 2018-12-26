//路径计数,矩阵 #include<cstdio>
#include<cstdio>
#include<cstring>
const int MAXN=107;
int dp[MAXN][MAXN];
int m[MAXN][MAXN];
int main(){
	int a,b;
	int test=1;
	while(scanf("%d%d",&a,&b)&&a+b){
		m[a][b]=1;
		while(scanf("%d%d",&a,&b)&&a+b)
			m[a][b]=1;
		int res=0,cnt=0;
		for(int i=1;i<=4;++i){
			for(int j=1;j<=4;++j){
				printf("%d ",m[i][j]);
			}
			printf("\n");
		}
		while(true){
			int sum=0,tmp=0;
			for(int i=1;i<=101;++i)
				for(int j=1;j<=101;++j)
					dp[i][j]=m[i][j];
			memset(m,0,sizeof(m));

			for(int i=1;i<=101;++i){
				for(int j=1;j<=101;++j){
					for(int k=1;k<=101;++k){
						m[i][j]+=dp[i][k]*dp[k][j];
							sum+=m[i][j];
						if(m[i][j])++tmp;
					}
				}
			}

			if(sum==0)break;
			res+=sum;cnt+=tmp;
		}
		printf("res=%d,cnt=%d\n",res,cnt);
	}
	return 0;
}
