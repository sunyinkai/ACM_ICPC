#include<cstdio>
const int MAXN=32;
long long res[MAXN];
int f[MAXN][2][2];
//f[i][x][y]:第i位倒数第1位为y,倒数第二位为x的合法情况数
void init(){
	res[1]=res[2]=0;
	f[2][0][0]=f[2][0][1]=f[2][1][0]=f[2][1][1]=1;
	long long power=4;
	for(int i=3;i<MAXN;++i){
		power*=2;
		f[i][0][0]=f[i-1][1][0];
		f[i][0][1]=f[i-1][0][0]+f[i-1][1][0];
		f[i][1][0]=f[i-1][0][1]+f[i-1][1][1];
		f[i][1][1]=f[i-1][0][1]+f[i-1][1][1];
		res[i]=power-f[i][0][0]-f[i][0][1]-f[i][1][0]-f[i][1][1];
	}
}
int main(){
	init();
	int n;
	while(scanf("%d",&n)&&n){
		printf("%lld\n",res[n]);
	}
	return 0;
}
