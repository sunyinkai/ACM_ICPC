#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=2007;
const int INF=1e9+7;
int a[MAXN];
map<int,int>mp;
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int ans=INF;
    for(int i=1;i<=n;++i){
        mp.clear();
        for(int j=1;j<=n;++j)mp[a[j]]++;
        if(mp.size()==n){
            ans=0;
            break;
        }
        for(int j=i;j<=n;++j){
            mp[a[j]]--;
            if(mp[a[j]]==0)mp.erase(a[j]);
            if(mp.size()==(n-(j-i+1)))ans=min(ans,j-i+1);
        }
    }
    printf("%d\n",ans);
    return 0;
}
