#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
inline int lowbit(int i){
	return i&-i;
}
int N;
int bit[MAXN]; 
void  add(int i,int y){
	while(i<MAXN){
		bit[i]+=y;
		i+=lowbit(i);
	}
}
int sum(int i){
	int res=0;
	while(i){
		res+=bit[i];
		i-=lowbit(i);
	}
	return res;
}
int x[MAXN],a[MAXN],b[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		memset(bit,0,sizeof(bit));
		for(int i=1;i<=N;++i){
			scanf("%d",&x[i]);
			if(i==1)a[i]=0;
			else a[i]=sum(x[i]);
			add(x[i],1);
			//printf("a[%d]=%d\n",i,a[i]);
		}
		memset(bit,0,sizeof(bit));
		for(int i=N;i>=1;--i){
			if(i==N)b[i]=0;
			else b[i]=sum(100001-x[i]);
			add(100001-x[i],1);
			//printf("b[%d]=%d\n",i,b[i]);
		}
		long long res=0;
		for(int i=1;i<=N;++i){
			res+=(long long )a[i]*b[i]+(long long)(i-1-a[i])*(N-i-b[i]);
		}
		printf("%lld\n",res);
	}
	return 0;
}
