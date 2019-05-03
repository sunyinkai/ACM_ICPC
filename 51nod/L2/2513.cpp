//tag: greedy,two_pointer
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+7;
int a[MAXN],b[MAXN];
int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<N;++i)
        scanf("%d",&b[i]);
    sort(a,a+N);
    sort(b,b+N);
    int i=0,j=0;//i point to a,j point to b
    int ans=0;
    while(i<N&&j<N){
        while(i<N&&a[i]<=b[j])++i;
        if(a[i]>b[j]){
            ++ans;
            ++i;
            ++j;
        }
    }
    printf("%d\n",ans);
    return 0;
}
