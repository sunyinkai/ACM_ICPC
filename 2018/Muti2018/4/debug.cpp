#include<cstdio>
#include<cstring>
const int MAXN=207;
int a[MAXN][MAXN],A[MAXN];
int L,N;
void generate(){
	int cursor=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<=i;++j){
			a[j][i-j]=A[cursor];
			cursor=(cursor+1)%L;
		}
	}
}
void print(){
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(a[i][j])printf("%d ",a[i][j]);
			else break;
		}
		printf("\n");
	}
}
int main(){
	N=40;
	scanf("%d",&L);
	for(int i=0;i<L;++i)scanf("%d",&A[i]);
	generate();
	print();
	return 0;
}
