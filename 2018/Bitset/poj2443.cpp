#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=1001;
const int MAXM=10007;
bitset<MAXN>bt[MAXM];
int main(){ 
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){ 
		int x;scanf("%d",&x);
		for(int j=0;j<x;++j){ 
			int val;scanf("%d",&val);
			bt[val][i]=1;//val出现在哪些集合里
		}
	}
	int Q;scanf("%d",&Q);
	while(Q--){ 
		int x,y;scanf("%d%d",&x,&y);
		//询问两个集合有没有交集
		bitset<MAXN>t=bt[x]&bt[y];
		if(t.any())printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
