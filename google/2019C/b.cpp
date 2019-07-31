#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=507;
const int INF=2e9+7;
int a[MAXN][MAXN];
int big[MAXN][MAXN][MAXN],small[MAXN][MAXN][MAXN];

int R,C,K;

void init(){
    //row i max[s,t],min[s,t]
    for(int i=1;i<=R;i++){
        for(int s=1;s<=C;s++){
            int maxVal=0,minVal=INF;
            for(int t=s;t<=C;t++){
                maxVal=max(maxVal,a[i][t]);
                minVal=min(minVal,a[i][t]);
                big[i][s][t]=maxVal;
                small[i][s][t]=minVal;
            }
        }
    }
}

int solve(int l,int r){
    int ans=0;
    int len=0;
    for(int row=1;row<=R;row++){
        int x=big[row][l][r];
        int y=small[row][l][r];
        if(x-y<=K){
            ++len;
        }else{
            ans=max(ans,len);
            len=0;
        }
    }
    ans=max(ans,len);
    return ans*(r-l+1);
}

int main(){
    int T;scanf("%d",&T);
    for(int test=1;test<=T;test++){
        scanf("%d%d%d",&R,&C,&K);
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++)
                scanf("%d",&a[i][j]);
        }

        init();
        int ans=0;
        for(int l=1;l<=C;l++){
            for(int r=l;r<=C;r++){
                ans=max(ans,solve(l,r));
            }
        }
        printf("Case #%d: %d\n",test,ans);
    }
    return 0;
}
