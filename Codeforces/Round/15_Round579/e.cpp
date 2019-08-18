#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+7;
int a[MAXN];
int visit[MAXN];
int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i)scanf("%d",&a[i]);
    sort(a,a+N);
    for(int i=0;i<N;++i){
        int x=a[i];
        if(x-1!=0&&!visit[x-1]){
            visit[x-1]=1;
        }else if(!visit[x]){
            visit[x]=1;
        }else if(!visit[x+1]){
            visit[x+1]=1;
        }else{
            ;
        }
    }
    int ans=0;
    for(int i=0;i<MAXN;++i)
        if(visit[i])++ans;
    printf("%d\n",ans);
    return 0;
}
