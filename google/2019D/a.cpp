#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int N,M;
bool isok(int val){
    int bit=0;
    for(int i=0;i<=10;++i){
        if(val&(1<<i))++bit;
    }
    return bit%2==0;
}

int solve(){
    int ans=0;
    for(int i=1;i<=N;++i){
        int val=0;
        for(int j=i;j<=N;++j){
            val^=a[j];
 //           printf("i:%d,j:%d,val:%d\n",i,j,val);
            if(isok(val))ans=max(ans,j-i+1);
        }
    }
    return ans;
}

int main(){
    int T;scanf("%d",&T);
    for(int test=1;test<=T;++test){
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;++i)
            scanf("%d",&a[i]);
        printf("Case #%d:",test);
        for(int k=1;k<=M;++k){
            int id,val;scanf("%d%d",&id,&val);
            a[id+1]=val;
            int ans=solve();
            printf(" %d",ans);
        }
        printf("\n");
    }
    return 0;
}
