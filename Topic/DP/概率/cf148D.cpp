#include<cstdio>
#include<cstring>
const int MAXN=1007;
double dp[MAXN][MAXN][2];
int visit[MAXN][MAXN][2];
//0 is princess,1 is dragon
double dfs(int w,int b,int status){
	//printf("w=%d,b=%d,status=%d\n",w,b,status);
	if(w<=0){
		 dp[0][b][1]=1.0;
		 dp[0][b][0]=0.0;
		 return dp[0][b][status];
	}
	if(b<=0){
		dp[w][0][status]=1.0;
		dp[w][0][1-status]=0.0;
		return dp[w][0][status];
	}
	if(visit[w][b][status])return dp[w][b][status];
	visit[w][b][status]=1;
	double res=w*1.0/(w+b);
	if(status==0){
		res+=b*1.0/(w+b)* (1.0-dfs(w,b-1,1));
	}else{
		res+=b*1.0/(w+b)* (((w*1.0/(w+b-1)*(1-dfs(w-1,b-1,0)))) + ((b-1)*1.0/(w+b-1)*(1-dfs(w,b-2,0))));
	}
	dp[w][b][status]=res;
	//printf("dp[%d][%d][%d]=%.9f\n",w,b,status,res);
	return dp[w][b][status];
}
int main(){
	int w,b;
	scanf("%d%d",&w,&b);
	memset(visit,0,sizeof(visit));
	printf("%.10f\n",dfs(w,b,0));
	return 0;
}
