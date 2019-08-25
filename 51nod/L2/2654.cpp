//tag: binary_search
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=1e5+7;
const int INF=1e9+7;

int a[MAXN];
int N,M;
bool isok(int dis){
    int prev=-INF;
    int cnt=0;
    for(int i=1;i<=N;++i){
        if(a[i]-prev>=dis){
            ++cnt;
            prev=a[i];
        }
    }
    return cnt>=M;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i)scanf("%d",&a[i]);
    sort(a+1,a+N+1);
    int lo=0-1,hi=INF+1;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(isok(mid))lo=mid;
        else hi=mid;
    }
    printf("%d\n",lo);
    return 0;
}
