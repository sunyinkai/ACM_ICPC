//tag: greedy,math
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
struct node{
    long long a,b;
    bool operator<(const node&other)const{// a/b max first;
        return a*other.b>b*other.a;
    }
}no[MAXN];
int D,S;
long long x[MAXN],y[MAXN];
void init(){
    for(int i=0;i<=S+1;++i)x[i]=y[i]=0;
    sort(no+1,no+S+1);
    for(int i=1;i<=S;++i){
        x[i]=x[i-1]+no[i].a;
    }
    for(int i=S;i>=1;--i){
        y[i]=y[i+1]+no[i].b;
    }
}
int main(){
    int T;scanf("%d",&T);
    for(int test=1;test<=T;++test){
        printf("Case #%d: ",test);
        scanf("%d%d",&D,&S);
        for(int i=1;i<=S;++i){
            scanf("%lld%lld",&no[i].a,&no[i].b);
        }
        init();
        for(int i=1;i<=D;++i){
            long long m,n;scanf("%lld%lld",&m,&n);
            long long id=lower_bound(x+1,x+1+S,m)-x;
            if(id>S){//x is not satisfy
                printf("N");
            }else{
                long long remain=x[id]-m;
                long long for_y=y[id+1];
                if(for_y>=n){
                    printf("Y");
                }else{
                    n-=for_y;
                    if(remain*no[id].b>=n*no[id].a)printf("Y");
                    else printf("N");
                }
            }
        }
        printf("\n");
        
    }
    return 0;
}
