#include<cstdio>
#include<cstring>
const int MAXN=1e4+7;
const int MAXM=1e6+7;
int s[MAXN],t[MAXM];
typedef unsigned long long ull;
ull base=1e9+7;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int lenB,lenA;scanf("%d%d",&lenB,&lenA);
		for(int i=0;i<lenB;++i)scanf("%d",&t[i]);
		for(int i=0;i<lenA;++i)scanf("%d",&s[i]);
		ull pow=1;
		for(int i=0;i<lenA;++i)pow=pow*base;
		ull A=0,B=0;
		for(int i=0;i<lenA;++i)
			A=A*base+s[i],B=B*base+t[i];
		int res=0;
		int i;
		bool hasAns=false;
		for(i=0;;++i){
			if(A==B){
				hasAns=true;
				break;
			}
			if(i+lenA>=lenB)break;
			B=B*base+t[i+lenA]-t[i]*pow;
		}
		if(hasAns)printf("%d\n",i+1);
		else printf("-1\n");//
	}
	return 0;
}
