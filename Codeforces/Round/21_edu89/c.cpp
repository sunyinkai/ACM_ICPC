#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=31;
int a[MAXN][MAXN];
int val[MAXN*2][2];
int val2[MAXN*2][2];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int N,M;scanf("%d%d",&N,&M);
        int cnt_0=0,cnt_1=0;
        memset(val,0,sizeof(val));
        memset(val2,0,sizeof(val2));

        for(int i=1;i<=N;++i)
            for(int j=1;j<=M;++j){
                scanf("%d",&a[i][j]);
                if(a[i][j]==0)cnt_0++;
                else cnt_1++;
                val[i+j-2][a[i][j]]++;
                val2[N+M-(i+j)][a[i][j]]++;
            }
        int ans=0;
        if((N+M)&1){
            ans=min(cnt_0,cnt_1);
        }else{
            int half=(N+M-2)/2;
            for(int i=0;i<half;++i){
                int tot=val[i][0]+val[i][1]+val2[i][0]+val2[i][1];
                int tot0=val[i][0]+val2[i][0];
                int tot2=val[i][1]+val2[i][1];
                ans+=min(tot-tot0,tot-tot2);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
