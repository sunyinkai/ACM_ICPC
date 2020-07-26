#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        for(int i=0;i<n;++i)scanf("%d",&a[i]);
        sort(a,a+n);
        int tot=unique(a,a+n)-a;
        printf("%d\n",tot);
    }
    return 0;
}
