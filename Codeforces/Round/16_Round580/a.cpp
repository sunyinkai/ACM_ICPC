#include<cstdio>
#define max(a,b) (a>b?a:b)
const int MAXN=407;
int main(){
    int N;scanf("%d",&N);
    int x=0,y=0;
    for(int i=0;i<N;++i){
        int a;scanf("%d",&a);
        x=max(a,x);
    }
    int M;scanf("%d",&M);
    for(int i=0;i<M;++i){
        int b;scanf("%d",&b);
        y=max(b,y);
    }
    printf("%d %d\n",x,y);
    return 0;
}
