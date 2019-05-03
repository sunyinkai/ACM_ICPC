//tag: binary,contribution
#include<cstdio>
const int MAXN=30;
int cnt[MAXN][2];
int main(){
    int N;scanf("%d",&N);
    while(N--){
        int x;scanf("%d",&x);
        for(int i=0;i<30;++i){
            cnt[i][x%2]++;
            x/=2;
        }
    }
    long long ans=0;
    for(int i=0;i<30;++i){
        ans+=cnt[i][0]*cnt[i][1];
    }
    printf("%lld\n",ans);
    return 0;
}
