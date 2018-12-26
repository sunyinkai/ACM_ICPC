/*
添加到这一行，同时为了维护一个对角矩阵，要先用下面的行消自己，再用自己消上面的行。
如果一个向量能被已有向量张成，它不应添加进，在高斯消元的过程中它必然是已经存在的行向量的线性组合，所以这个方程实际上是多余的，它最后一定会被异或为一个0。反之如果向量张成，那么它一定能找到某一个行添加进去。	
*/
//对角阵
//O(N*K^2)
//对于最后得到的矩阵，如果第i的主对角线上为1，此时我们称第i位存在于线性基中
//对于不在线性基中的二进制位i，那么第i行主对角线下方全为0，而主对角线上方就可能有若干个1
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAX_BASE=62;
const int MAXN=1e5+7;
long long b[MAX_BASE],a[MAXN];
int n;
void linear_base(){
	for (int i=0;i<n;++i)
	for (int j=MAX_BASE;j>=0;--j)
		if(a[i]&((LL)1<<j)){
			if (b[j])a[i]^=b[j];
			else {
				b[j]=a[i];
				for(int k=j-1;k>=0;--k)if(b[k]&&(b[j]&((LL)1<<k)))b[j]^=b[k];
				for(int k=j+1;k<=MAX_BASE;++k)if(b[k]&((LL)1<<j))b[k]^=b[j];
				break;
			}
		}
}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%lld",&a[i]);
	linear_base();
	for(int i=MAX_BASE;i>=0;--i){
		long long val=b[i];

		int x[MAX_BASE+5];
		for(int j=0;j<=MAX_BASE;++j){
			x[j]=val%2;
			val/=2;
		}
		reverse(x,x+MAX_BASE+1);
		for(int j=0;j<=MAX_BASE;++j)
			printf("%d",x[j]);
		printf("\n");
	}
	return 0;
}
