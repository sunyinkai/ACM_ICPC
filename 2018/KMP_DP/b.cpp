#include<cstdio>
#include<cstring>
const int MAXN=1007,MAXM=12;
double dp[MAXN][MAXM];
//dp[i][j]:在第i个操作后已经匹配目标字符串的位置的个数
double p[MAXN];
char s[MAXM];
int next[MAXM];
int N,M,C;

void getNext(){ 
	int i=0,j=next[0]=-1;
	while(i<M){ 
		while(j!=-1&&s[i]!=s[j])j=next[j];
		next[++i]=++j;
	}
	//for(int i=0;i<M;++i) printf("%d\n",next[i]);
}

int main(){ 
	while(~scanf("%d%d",&C,&N)&&N+C){ 
		getchar();
		memset(p,0,sizeof(p));
		for(int i=0;i<C;++i){ 
			char ch=getchar();
			double p0;
			scanf("%lf",&p0);
			p[ch]=p0;
			getchar();
		}
		scanf("%s",s);
		M=strlen(s);
		getNext();
		
		//DP
		memset(dp,0,sizeof(dp));

		dp[0][0]=100.0;
		for(int i=0;i<N;++i){ 
			for(int j=0;j<M&&j<=i;++j){ 
				for(int k='a';k<='z';++k){ 
					if(!p[k])continue;
					if(s[j]==k)dp[i+1][j+1]+=dp[i][j]*p[k];//match
					else{ //next数组
						int t=j;
						while(t!=-1&&s[t]!=k)t=next[t];
						dp[i+1][t+1]+=p[k]*dp[i][j];
					}
				}
			}
			
			//感觉前面已经组成了目标字符串的不好处理
		}
		double ans=0.0;
		for(int i=0;i<=N;++i)ans+=dp[i][M];
		printf("%.2f%%\n",ans);
	}
	return 0;
}
