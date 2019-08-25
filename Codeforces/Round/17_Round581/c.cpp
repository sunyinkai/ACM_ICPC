#include<cstdio>
#include<map>
using namespace std;

const int MAXN=107;
const int INF=1e9+7;
const int MAXM=1e6+7;
int dp[MAXN][MAXN];

int a[MAXM];
int ans[MAXM];
map<int,int>mp;

int n;
void floyd(){
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        char s[MAXN];scanf("%s",s);
        for(int j=0;j<n;++j){
            if(s[j]=='1'){
                dp[i+1][j+1]=1;
            }else{
                dp[i+1][j+1]=INF;
            }
        }
        dp[i+1][i+1]=0;
        dp[0][i+1]=dp[i+1][0]=INF;
    }
    floyd();
    int M;scanf("%d",&M);
    for(int i=1;i<=M;++i){
        scanf("%d",&a[i]);
    }
    int top=0;
    for(int i=1;i<=M;++i){
        if(i==1){
            ans[top++]=a[i];
            mp[a[i]]=1;
        }
        else{
          /*  for(auto it=mp.begin();it!=mp.end();it++){
                printf("%d ",it->first);
            }
            printf("\n-----\n");*/
           if(!mp[a[i]]){
               mp[a[i]]=1;
            }else{
                if(a[i]!=ans[top-1])ans[top++]=a[i];
                if(a[i-1]!=ans[top-1])ans[top++]=a[i-1];
                mp.clear();
                mp[a[i-1]]=1;
                continue;
            }
            if(dp[a[i-1]][a[i+1]]!=dp[a[i-1]][a[i]]+dp[a[i]][a[i+1]]){
               if(a[i]!=ans[top-1]) ans[top++]=a[i];
                mp.clear();
                mp[a[i]]=1;
            }else{

            }
        }
    }
    printf("%d\n",top);
    for(int i=0;i<top;++i){
        if(i==0)printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }
    printf("\n");
    return 0; 
}
