#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long  mod=998244353;
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	long long dp0[2][3];//当前处理到有i个球,j个拍的方案数
	int n=a+b+c+d;
	memset(dp0,0,sizeof(dp0));
	dp0[0][0]=1;
	for(int i=0;i<n;++i){
		long long dp2[2][3];
		memset(dp2,0,sizeof(dp2));
		if(i<a){//无球无拍
			for(int i=0;i<=1;++i)
				for(int j=0;j<=2;++j)
					dp2[i][j]=(dp0[i][j]+dp0[i][j])%mod;
		}else if(i>=a&&i<a+b){//只有拍
				for(int i=0;i<=1;++i)
					for(int j=0;j<=2;++j){
						int ni=i,nj=j+1;
						dp2[i][min(nj,2)]=(dp2[i][min(nj,2)]+dp0[i][j])%mod;//choose
						dp2[i][j]=(dp2[i][j]+dp0[i][j])%mod;//don't
					}
		}else if(i>=a+b&&i<a+b+c){//只有球
			for(int i=0;i<=1;++i)
				for(int j=0;j<=2;++j){
					int ni=i+1,nj=j;
					dp2[min(ni,1)][j]=(dp2[min(ni,1)][j]+dp0[i][j])%mod;//choose
					dp2[i][j]=(dp2[i][j]+dp0[i][j])%mod;//don't
				}
		}else{//有球有拍
			for(int i=0;i<=1;++i)
				for(int j=0;j<=2;++j){
					int ni=i+1,nj=j+1;
					dp2[min(ni,1)][min(nj,2)]=(dp2[min(ni,1)][min(nj,2)]+dp0[i][j])%mod;//choose
					dp2[i][j]=(dp2[i][j]+dp0[i][j])%mod;//don't
				}
		}
		for(int i=0;i<=1;++i)for(int j=0;j<=2;++j){
			dp0[i][j]=dp2[i][j];
		//	printf("dp0[%d][%d]=%lld\n",i,j,dp0[i][j]);
		}
	}
	long long ans=0;
	for(int i=0;i<=1;++i)
		for(int j=0;j<=2;++j){
			if(!(i==1&&j==2))ans=(ans+dp0[i][j])%mod;
		}
	printf("%lld\n",ans);
	return 0;
}
