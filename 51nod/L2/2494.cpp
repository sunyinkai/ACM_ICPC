//tag: prefix_sum
#include<cstdio>
#include<algorithm>
#include<unordered_map>
using namespace std;
unordered_map<int,int>mp;
int main(){
    int N;scanf("%d",&N);
    int sum=0;
    int ans=0;
    mp[0]=0;
    for(int i=1;i<=N;++i){
        int x;scanf("%d",&x);
        if(x==0) x=-1;
        sum+=x;
   //     printf("sum:%d\n",sum);
        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }else{
            ans=max(ans,i-mp[sum]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
