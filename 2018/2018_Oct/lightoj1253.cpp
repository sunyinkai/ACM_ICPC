#include<cstdio>
#include<cstring>
const int MAXN=207;
int x[MAXN];
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		long long res=0;
		int N;scanf("%d",&N);
		for(int i=0;i<N;++i){
			scanf("%d",&x[i]);
			res^=x[i];
		}
		printf("Case %d: ",test);
		bool P=false;
		if(res==1)P=true;
		int k=0;
		res^=1;
		while(res){
			res/=2;
			++k;
		}
		bool isok=false;
		for(int i=0;i<N;++i){
			if((1<<k)&&x[i])isok=true;
		}
		if(!isok)P=true;
		if(P)printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}
