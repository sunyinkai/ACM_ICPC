//tag: binary_search
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=2e5+7;
int n,k,a,m;
int x[MAXN];
int t[MAXN];
int isok(int mid){
    for(int i=1;i<=mid;++i)
        t[i]=x[i];
    sort(t+1,t+mid+1);
    t[mid+1]=n+1;

    int prev=0;
    int cnt=0;
    for(int it=1;it<=mid+1;++it){
        cnt+=(t[it]-prev)/(a+1);
        prev=t[it];
    }
    return cnt>=k;
}

int main(){
    scanf("%d%d%d",&n,&k,&a);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)scanf("%d",&x[i]);
    int lo=0,hi=m+1;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(isok(mid))lo=mid;
        else hi=mid;
    }
    if(hi==m+1)printf("-1");
    else printf("%d\n",hi);
    return 0;
}
