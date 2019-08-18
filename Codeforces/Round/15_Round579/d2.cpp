#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=2e5+7;
char s[MAXN],t[MAXN];
int x[MAXN],y[MAXN];
int len_s,len_t;
void solve(const char*s,const char*t,int *dp){
    int i=0,j=0;
    while(i<len_s&&j<len_t){
        if(t[j]!=s[i])++i;
        else{
            ++i;++j;
            dp[j]=i;
        }
    }
}

int main(){
    //t is subquence of s
    scanf("%s",s);
    scanf("%s",t);
    len_s=strlen(s);
    len_t=strlen(t);
    solve(s,t,x);

    reverse(t,t+len_t);
    reverse(s,s+len_s);
    solve(s,t,y);
    for(int i=1;i<=len_t;++i)
        y[i]=len_s+1-y[i];
    
    /*for(int i=1;i<=len_t;++i){
        printf("x[%d]:%d,y[%d]:%d\n",i,x[i],i,y[i]);
    }
    printf("begin:%d\n",len_s-x[len_t]);
    printf("end:%d\n",y[len_t]-1);
    */

    int ans=max(len_s-x[len_t],y[len_t]-1);
    for(int i=1;i<len_t;++i){
        int front=x[i];
        int back=y[len_t-i];
      //  printf("front:%d,back:%d\n",front,back);
        ans=max(ans,back-front-1);
    }
    printf("%d\n",ans);
    return 0;
}
