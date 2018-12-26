#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=15;
const int MAXM=107;
const int INF=2e9+7;

int dp[MAXN][MAXM];
int a[MAXN][MAXM];
int par[MAXN][MAXM];
int ans[MAXM];

bool small(int *x,int *y,int len){//x是不是比y小
	int i;
	for(i=0;i<len&&(x[i]==y[i]);++i);
	if(i==len)return false;
	else if(x[i]<y[i])return true;
	else return false;
}

int main(){
	int N,M;
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d%d",&N,&M)){
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
				scanf("%d",&a[i][j]);

		for(int i=0;i<=N;++i)
			for(int j=0;j<=M;++j)
				dp[i][j]=INF;
		
		for(int i=0;i<N;++i)dp[i][0]=a[i][0];

		for(int j=1;j<M;++j){
			for(int i=0;i<N;++i){
				int id=INF;
				int x=dp[(i-1+N)%N][j-1]+a[i][j];
				if(dp[i][j]>=x){//从左上方转移过来(i-1,j-1)
					if(dp[i][j]>x)id=(i-1+N)%N;
					else id=min(id,(i-1+N)%N);
					dp[i][j]=x;
				}
				x=dp[(i+N)%N][j-1]+a[i][j];
				if(dp[i][j]>=x){//(i,j-1);//左边(i,j-1);
					if(dp[i][j]>x)id=(i+N)%N;
					else id=min(id,(i+N)%N); 
					dp[i][j]=x;
				}
				x=dp[(i+1+N)%N][j-1]+a[i][j];
				if(dp[i][j]>=x){//左下(i+1,j)
					if(dp[i][j]>x)id=(i+1+N)%N;
					else id=min(id,(i+1+N)%N);
					dp[i][j]=x;
				}
				par[i][j]=id*M+j-1;
				printf("(%d,%d)->(%d,%d)\n",id,j-1,i,j);
			}
		}

		int res=INF;
		int id[MAXM],top=0;
		for(int i=0;i<N;++i)
			if(dp[i][M-1]<res)res=dp[i][M-1];
		for(int i=0;i<N;++i)
			if(res==dp[i][M-1])id[top++]=i;

		int tmp[MAXM];
		for(int i=0;i<MAXM;++i)ans[i]=INF;
		printf("top=%d\n",top);
		for(int i=0;i<top;++i){
			int num=0;
			int nowx=id[i];//id[i]行，M-1列
			int nowy=M-1;
			tmp[num++]=nowx+1;//记录
			printf("\n(%d,%d)\n",nowx,nowy);
			while(1){
				int now=par[nowx][nowy];
				nowx=now/M,nowy=now%M;
				tmp[num++]=nowx+1;
				printf("(%d,%d)\n",nowx,nowy);
				if(nowy==0)break;
			}
			reverse(tmp,tmp+num);
			if(small(tmp,ans,num)){
				for(int i=0;i<M;++i)
					ans[i]=tmp[i];
			}
		}
		for(int i=0;i<M;++i)
			printf(i==0?"%d":" %d",ans[i]);
		printf("\n");
		printf("%d\n",res);

	}
	return 0;
}
