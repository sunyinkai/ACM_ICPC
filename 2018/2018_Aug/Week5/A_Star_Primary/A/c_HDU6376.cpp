#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+7;
char s[MAXN];
int q[MAXN],dp[MAXN];
int w[MAXN],v[MAXN];
int main(){
	int N,K;
	while(~scanf("%d%d",&N,&K)){
		scanf("%s",s);
		int begin=0;
		int i;
		for(i=0;i<N;++i){
			if(s[i]=='1'){
				++begin;
			}else{
				break;
			}
		}
		if(begin==N){
			printf("%d\n",N);continue;
		}
		if(K==0){
			printf("%d\n",begin);
			continue;
		}
		//tail
		int end=0;
		int j;
		for(j=N-1;j>=0;--j){
			if(s[j]=='1'){
				++end;
			}else{
				break;
			}
		}
		
		int top=0;
		int cnt=0;
		for(int k=i;k<j;++k){
			if(s[k]=='1'){
				++cnt;
			}else{
				q[top++]=cnt;
				cnt=0;
			}
		}
		q[top++]=cnt;
		sort(q,q+top);

		//bag
		int up=0;
		w[up]=1,v[up++]=begin;
		w[up]=1,v[up++]=end;
		for(int i=0;i<top;++i){
			if(q[i]==0)continue;
			w[up]=2;v[up++]=q[i];
		}

		/*for(int i=0;i<up;++i){
			printf("w[i]=%d,v[i]=%d\n",w[i],v[i]);
		}*/

		++K;
		for(int i=0;i<=K;++i)dp[i]=0;
		for(int i=0;i<up;++i){
			for(int j=K;j>=w[i];j--){
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		printf("%d\n",dp[K]);
	}
	return 0;
}

