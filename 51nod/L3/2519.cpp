//tag: greedy,logic
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7; 
int mp[MAXN],a[MAXN];
int b[MAXN];

int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+N);
    int top=0;//the array b
    for(int i=0;i<N;++i){
        if(mp[a[i]])b[top++]=a[i];
        mp[a[i]]=1;
    }

    int now=1;
    int ans=0;
    for(int i=0;i<top;++i){
        if(b[i]>=now)now=b[i];
        while(mp[now])++now;
        mp[now]=1;
        ans+=now-b[i];
    }
    printf("%d\n",ans);
    return 0;
}
