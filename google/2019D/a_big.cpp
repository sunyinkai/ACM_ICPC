#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int N,M,sumVal;

int getBit(int val){
    int bit=0;
    for(int i=0;i<=10;++i){
        if(val&(1<<i))++bit;
    }
    return bit;
}

set<int>odd,even;// id

int solve(){
    int ans=0;
    if(sumVal%2==0)return N;
    else{
        auto it=odd.begin();
        ans=max(ans,*it-1);
        ans=max(ans,N-*it);
        auto its=odd.rbegin();
        ans=max(ans,*its-1);
        ans=max(ans,N-*its);
    }
    return ans;
}


int main(){
    int T;scanf("%d",&T);
    for(int test=1;test<=T;++test){
        odd.clear();even.clear();
        scanf("%d%d",&N,&M);
        sumVal=0;
        for(int i=1;i<=N;++i){
            scanf("%d",&a[i]);
            a[i]=getBit(a[i]);
            if(a[i]&1){
                odd.insert(i);
            }else{
                even.insert(i);
            }
            sumVal+=a[i];
        }

        printf("Case #%d:",test);
        for(int k=1;k<=M;++k){
            int id,val;scanf("%d%d",&id,&val);
            sumVal-=a[id+1];
            if(a[id+1]&1){
                odd.erase(id+1);
            }else{
                even.erase(id+1);
            }
            
            int cnt=getBit(val);
            if(cnt&1){
                odd.insert(id+1);
            }else{
                even.insert(id+1);
            }
            
            a[id+1]=cnt;
            sumVal+=cnt;
            int ans=solve();
            printf(" %d",ans);
        }
        printf("\n");
    }
    return 0;
}

