#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e9+7;
int a,b,tot;
bool hasAns;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
LL ans[100],res[100];
LL minFenmu;
void  dfs(int now,int dep,LL fenzi,LL fenmu,LL prev){//prev单调递增
	if(now>=dep)return ;
	LL limit=max(fenmu/fenzi,prev+1);
	for(LL i=limit;i<=ceil((double)fenmu*(dep-now)/fenzi);++i){
		if(i>minFenmu)return ;
		if(fenmu>i*fenzi)continue;
		else if(fenmu==i*fenzi){
			hasAns=true;
			ans[tot++]=i;
			if(i<res[tot-1]){
				for(int k=0;k<tot;++k){
					res[k]=ans[k];
				}
			}
			minFenmu=min(minFenmu,i);//已经得到的解的最小分母的值,用于剪枝
			--tot;
			return ;
		}else{
			LL aa=fenzi*i-fenmu;
			LL bb=fenmu*i;
			LL GCD=gcd(aa,bb);
			ans[tot++]=i;
			dfs(now+1,dep,aa/GCD,bb/GCD,i);
			tot--;//回溯
		}
	}
	return ;
}
int main(){
	scanf("%d%d",&a,&b);
	int k=1;
	hasAns=false;
	tot=0;
	minFenmu=INF;
	for(int i=0;i<100;++i)res[i]=INF;
	for(;;){
		dfs(0,k,a,b,0);
		if(hasAns){
			break;
		}
		k++;
	}
	for(int i=0;i<k;++i){
		printf("%lld ",res[i]);
	}
	printf("\n");
	return 0;
}
