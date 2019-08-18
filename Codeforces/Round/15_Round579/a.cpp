#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=207;
int a[MAXN];
int b[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int N;scanf("%d",&N);
        for(int i=1;i<=N;++i){
            scanf("%d",&a[i]);
            a[N+i]=a[i];
            b[i]=i;
        }
        bool hasAns=false;
        for(int i=1;i<=N+1;++i){
            int k;
            for(k=0;k<N;++k){
                if(b[1+k]==a[i+k]);
                else break;
            }
            if(k==N)hasAns=true;
        }
        
        reverse(b+1,b+N+1);
        for(int i=1;i<=N+1;++i){
            int k;
            for(k=0;k<N;++k){
                if(b[1+k]==a[i+k]);
                else break;
            }
            if(k==N)hasAns=true;
        }
        
        printf(hasAns?"YES\n":"NO\n");
    }
    return 0;
}
