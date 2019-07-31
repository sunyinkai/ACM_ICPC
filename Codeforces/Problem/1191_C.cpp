#include<cstdio>
const int MAXN=1e5+7;
long long a[MAXN];
int main(){
    long long n,m,k;scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;++i)
        scanf("%lld",&a[i]);

    int ans=0;
    for(int i=1;i<=m;){//index
        long long stage=(a[i]-i)/k;
        int j;
        for(j=i;j<=m;){
            if((a[j]-i)/k==stage){
                ++j;
            }else{
                break;
            }
        }
        ++ans;
        i=j;
    }
    printf("%d\n",ans);
    return 0;
}
