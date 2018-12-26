#include<cstdio>
const int MAXN=37;
int N,K;
struct node{
	long long a[MAXN][MAXN];
};
node multi(node x,node y){
	node t;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			t.a[i][j]=0;
			for(int k=0;k<N;++k){
				t.a[i][j]+=x.a[i][k]*y.a[k][j];
			}
		}
	}
	return t;
}

int main(){
	scanf("%d%d",&N,&K);
	node  tmp;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			scanf("%lld",&tmp.a[i][j]);
	node res=tmp;
	for(int i=1;i<K;++i){
		res=multi(res,tmp);
	}
	printf("%lld\n",res.a[0][N-1]);
	return 0;
}
