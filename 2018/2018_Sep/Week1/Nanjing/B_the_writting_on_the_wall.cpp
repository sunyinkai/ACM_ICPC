#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
const int MAXM=107;
int q[MAXM],id[MAXM];
bool a[MAXN][MAXM];
int prev[MAXN][MAXM];
int l[MAXM],r[MAXM];
//一行一行计算,所有区间最小值之和
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		int N,M,K;scanf("%d%d%d",&N,&M,&K);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)a[i][j]=0,prev[i][j]=0;

		for(int i=0;i<K;++i){
			int x,y;scanf("%d%d",&x,&y);
			a[x][y]=1;
		}

		for(int i=1;i<=N;++i){
			for(int j=1;j<=M;++j){
				if(a[i][j]){
					prev[i][j]=i;
				}else{
					prev[i][j]=prev[i-1][j];
				}
			}
		}//init
		long long res=0;
		//l to r 单调不减
		for(int i=1;i<=N;++i){
			int top=0;
			for(int j=1;j<=M+1;++j){
				int len=i-prev[i][j];
				if(j==M+1)len=-1;//最后一个
				if(top==0||len>=q[top-1]){q[top]=len;id[top++]=j;}
				else{
					while(top>0&&len<q[top-1]){
						int ii=id[top-1];
						r[ii]=j-1;
						top--;
					}
					q[top]=len;id[top++]=j;
				}
			}
			//r 到 l 严格递增
			top=0;
			for(int j=M;j>=0;--j){
				int len=i-prev[i][j];
				if(j==0)len=-1;
				if(top==0||len>q[top-1]){q[top]=len;id[top++]=j;}
				else{
					while(top>0&&len<=q[top-1]){
						int ii=id[top-1];
						l[ii]=j+1;
						top--;
					}
				}
				q[top]=len;id[top++]=j;
			}
			for(int j=1;j<=M;++j){
				res+=((long long)j-l[j]+1)*((long long)r[j]-j+1)*((long long)i-prev[i][j]);
			}
		}
		printf("Case #%d: %lld\n",test,res);
	}
	return 0;
}
