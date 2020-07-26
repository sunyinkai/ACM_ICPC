#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXM=207;
struct node{
    int l,r;
    bool operator<(const node&other)const{
        return l<other.l||(l==other.l&&r<other.r);
    }
}a[MAXM],ans;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,x,m;scanf("%d%d%d",&n,&x,&m);
        for(int i=0;i<m;++i){
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        int top=0;
        ans.l=x;ans.r=x;
        for(int i=0;i<m;++i){
            if(a[i].r<ans.l || a[i].l>ans.r){
                continue;
            }else{
                ans.l=min(ans.l,a[i].l);
                ans.r=max(ans.r,a[i].r);
            }
        }
        printf("%d\n",ans.r-ans.l+1);
    }
    return 0;
}
