#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1e5+7;
vector<int>G[MAXN];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	if(N>M+1||N==1){
		printf("Impossible\n");
		return 0;
	}
	int K=0;
	int from=1,to=from+1;
	while(K<M){
		if(gcd(from,to)==1){
			++K;
			G[from].push_back(to);
	//		printf("from=%d,to=%d\n",from,to);
		}

		++to;
		if(to==N+1){
			++from;
			to=from+1;
		}
		if(from==N)break;
	}
	if(K==M){
		printf("Possible\n");
		for(int i=1;i<N;++i){
			int len=G[i].size();
			for(int j=0;j<len;++j)
				printf("%d %d\n",i,G[i][j]);
		}
	}else{
		printf("Impossible\n");
	}
	return 0;
}
