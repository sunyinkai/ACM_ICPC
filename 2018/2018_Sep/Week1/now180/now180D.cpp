#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_BASE=35;
const int MAXN=1e5+7;
typedef long long LL;
long long a[MAXN],b[MAX_BASE+3];
int n;
void linear_base(){
    for (int i = 0; i < n; ++i)
        for (int j = MAX_BASE; j >= 0; --j)
            if (a[i] >> j & (LL)1) {
                if (b[j]) a[i] ^= b[j];
                else {
                    b[j] = a[i];
                    for (int k = j - 1; k >= 0; --k) if (b[k] && ((b[j] >> k) & (LL)1)) b[j] ^= b[k];
                    for (int k = j + 1; k <= MAX_BASE; ++k) if ((b[k] >> j) & (LL)1) b[k] ^= b[j];
                    break;
                }
            }
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%lld",&a[i]);
	linear_base();
	int Q;scanf("%d",&Q);
	while(Q--){
		long long x,y;scanf("%lld%lld",&x,&y);
		long long val=x^y;
		for(int i=MAX_BASE;i>=0;--i){
			int num[36],top=0;
			long long x=b[i];
			for(int k=0;k<=32;++k){
				num[top++]=x%2;
				x/=2;
			}
			reverse(num,num+top);
			for(int k=1;k<=32;++k){
				printf("%d",num[k]);
			}
			printf("\n");
		}
		if(val==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
