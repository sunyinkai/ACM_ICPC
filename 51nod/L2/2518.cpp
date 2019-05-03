//tag: binary_search
#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e4+7;
int sum[MAXN];
int main(){
    int N;scanf("%d",&N);
    scanf("%d",&sum[0]);
    for(int i=1;i<N;++i){
        int x;scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
    int S;scanf("%d",&S);
    int ans=0;
    int prev=0;
    int id=0;
    for_each(sum,sum+N,[&](int x){
       int val=upper_bound(sum+id,sum+N,prev+S)-lower_bound(sum+id,sum+N,prev+S);
       ans+=val;
       ++id;
       prev=x;
//       printf("x:%d,val:%d\n",x,val);
     });
    printf("%d\n",ans);
    return 0;
}

