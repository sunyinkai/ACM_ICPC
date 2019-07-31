#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int MAXN=3e5+7;
struct node{
    long long t,b;
    bool operator<(const node&other)const{
        return b>other.b;
    }
}no[MAXN];
priority_queue<int,vector<int>,greater<int> >pq;

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%lld%lld",&no[i].t,&no[i].b);
    }
    sort(no,no+n);
    //init
    pq.push(no[0].t);
    long long ans=no[0].t*no[0].b;
    long long sum=no[0].t;

    for(int i=1;i<n;++i){
        if(i<m){
            pq.push(no[i].t);
            sum+=no[i].t;
        }
        else{
           long long min_val=pq.top();pq.pop();
           sum=sum-min_val+no[i].t;
           pq.push(no[i].t);
        }
        ans=max(ans,sum*no[i].b);
    }
    printf("%lld\n",ans);
    return 0;
}
