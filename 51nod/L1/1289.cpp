#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;

int x[MAXN],d[MAXN];
int visit[MAXN];
//case 
// 4  8 1  9 0   1 0    2 0
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d%d",&x[i],&d[i]);
	// direction: 1
	int prev=-1;
	for(int i=1;i<=N;++i){
		if(d[i]==1){
			prev=max(prev,x[i]);
		}else{
			if(prev>x[i])visit[i]=1;
			else prev=-1;//否则应该是被吃，就没办法考虑这条大鱼后面的了
		}
	}
	prev=-1;
	for(int i=N;i>=1;--i){
		if(d[i]==0)prev=max(prev,x[i]);
		else{
			if(prev>x[i])visit[i]=1;
			else prev=-1;
		}
	}

	int ans=0;
	for(int i=1;i<=N;++i){
		if(!visit[i]){
			++ans;
		//	printf("%d\n",i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
