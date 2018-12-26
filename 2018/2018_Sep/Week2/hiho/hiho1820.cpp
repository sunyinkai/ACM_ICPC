#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int main(){
    int N;scanf("%d",&N);
    long long sum=0;
    for(int i=0;i<N;++i){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a,a+N);
    int now=a[0];
    for(int i=0;i<N;){
        while(a[i]==now){
			sum-=a[i];
			++i;
		}
        printf("%lld\n",sum-(long long)(N-i)*now);
        now=a[i];
    }
    return 0;
}
