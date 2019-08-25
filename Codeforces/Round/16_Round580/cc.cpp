#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+7;
int a[MAXN];
int main(){
    int N;scanf("%d",&N);
    if(N==1){
        printf("YES\n");
        printf("1 2\n");
        return 0;
    }
    if(N%2==0){
        printf("NO\n");
        return 0;
    }
    a[1]=1;a[N+1]=2;
    int i=2,j=N+2;
    int val=3;
    while(val<=2*N){
        if((val/2)%2==1){
            a[j++]=val;
        }else{
            a[i++]=val;
        }
        val++;
    }

    printf("YES\n");
    for(int i=1;i<=2*N;++i)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
