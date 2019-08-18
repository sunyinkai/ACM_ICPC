#include<cstdio>
const int MAXN=1e5+7;
int a[MAXN];
int n,m;
bool isok(int val){
    if(val==0)return true;
    int ans=0;
    for(int i=0;i<n;++i){
        ans+=a[i]/val;
    }
    return ans>=m;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    int lo=-1,hi=1e9+7;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(isok(mid))lo=mid;
        else hi=mid;
    }
    printf("%d\n",lo);
    return 0;
}
