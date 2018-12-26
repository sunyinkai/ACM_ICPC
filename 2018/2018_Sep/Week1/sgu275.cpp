#include<cstdio>
const int MAX_BASE=62;
const int MAXN=120;
typedef long long LL;
long long a[MAXN],b[MAX_BASE+3];
int n;
void linear_base(){
//O(N*K^2)
//对于最后得到的矩阵，如果第i的主对角线上为1，此时我们称第i位存在于线性基中
//对于不在线性基中的二进制位i，那么第i行主对角线下方全为0，而主对角线上方就可能有若干个1
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
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%lld",&a[i]);
	linear_base();
	long long res=0;
	for(int i=0;i<=MAX_BASE;++i){
		if(b[i]&((long long)1<<i))res^=b[i];
	}
	printf("%lld\n",res);
	return 0;
}
