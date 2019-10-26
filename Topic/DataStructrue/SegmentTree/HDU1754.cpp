#include<cstdio>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;
const int MAXN=2e5+7;
int a[MAXN<<2];
void PushUp(int rt){
    a[rt]=max(a[rt<<1],a[rt<<1|1]);
}
void build(int l,int r,int rt){
    if(l==r){
        scanf("%d",&a[rt]);
        return ;
    }
    int m=(l+r)/2;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int x,int val,int l,int r,int rt){
    if(l==r){
        a[rt]=val;
        return ;
    }
    int m=(l+r)/2;
    if(x<=m)update(x,val,lson);
    else update(x,val,rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(l>=L&&r<=R)return a[rt];
    int m=(l+r)/2;
    int ans=0;
    if(L<=m)ans=max(ans,query(L,R,lson));
    if(R>m)ans=max(ans,query(L,R,rson));
    return ans;
}   

int main(){
    int N,M;
    while(~scanf("%d%d",&N,&M)){
        build(1,N,1);
        while(M--){
            char s[3];int a,b;
            scanf("%s%d%d",s,&a,&b);
            if(s[0]=='U'){
                update(a,b,1,N,1);
            }else{
                printf("%d\n",query(a,b,1,N,1));
            }
        }
    }
    return 0;
}
