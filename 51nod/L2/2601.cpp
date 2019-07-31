//tag: logic
#include<cstdio>
#define max(a,b) (a>b?a:b)
const int MAXN=1e5+7;
int a[MAXN],b[MAXN];
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=N;++i){
        scanf("%d",&b[i]);
    }
    return 0;
}
