#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int ans[MAXN],top;

long long C(long long x){
    return x*(x-1)/2;
}

int solve(int N){
    long long lo=-1,hi=1e5+7;
    while(hi-lo>1){
        long long mid=(hi+lo)/2;
        if(C(mid)>N)hi=mid;
        else lo=mid;
    }
    ans[top++]=lo;
    return N-lo*(lo-1)/2;
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        top=0;
        int N;scanf("%d",&N);
        while(N){
            N=solve(N);
 //           printf("N=%d,val=%d\n",N,ans[top-1]);
        }
        reverse(ans,ans+top);
        int k=0;
        printf("1");
        for(int i=0;;){
            printf("3");
            ++i;
            while(k!=top&&i==ans[k]){
                printf("7");
                k++;
            }
            if(k==top)break;
        }
        printf("\n");
    }
    return 0;
}
