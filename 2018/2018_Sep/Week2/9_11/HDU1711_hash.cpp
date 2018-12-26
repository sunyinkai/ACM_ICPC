#include<cstdio>
typedef unsigned long long ull;
const int MAXN=1e6+7,MAXM=1e4+7;
const ull seed0=1e9+7;
int s[MAXN],t[MAXM];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N,M;scanf("%d%d",&N,&M);
		for(int i=0;i<N;++i)scanf("%d",&s[i]);
		for(int i=0;i<M;++i)scanf("%d",&t[i]);
		ull power=1;
		for(int i=0;i<M;++i)power*=seed0;
		ull val0=0,val2=0;
		for(int i=0;i<M;++i)
			val0=val0*seed0+t[i],val2=val2*seed0+s[i];
		int ans=-1;
		for(int i=0;;++i){
			if(val2==val0){ans=i+1;break;}
			if(i+M>=N)break;
			val2=val2*seed0+s[i+M]-s[i]*power;
		}
		printf("%d\n",ans);
	}
	return 0;
}
