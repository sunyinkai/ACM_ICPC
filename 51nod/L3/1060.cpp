#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=107;
const long long INF=1e15+7;
int prim[MAXN],top;
long long N;
long long min_val,max_cnt;
void init(){
    top=0;
    for(int i=2;i<=10000&&top<MAXN;++i){
        bool isprime=true;
        for(int j=2;j*j<=i;++j){
            if(i%j==0){
                isprime=false;
                break;
            }
        }
        if(isprime){
            prim[top++]=i;
        }
    }
}

void dfs(int id,int prev_cnt,long long prefix_cnt,long long prefix_val){
    //get the ans
    if(prefix_cnt>=max_cnt){
        if(prefix_cnt==max_cnt){
            min_val=min(min_val,prefix_val);
        }
        else{
            min_val=prefix_val;
            max_cnt=prefix_cnt;
        }
    }

    long long next_val=prim[id];
    for(int i=1;i<=prev_cnt;++i){
        if(prefix_val<=N/next_val){
            dfs(id+1,i,prefix_cnt*(i+1),prefix_val*next_val);
            if(next_val<=N/prim[id]){
                next_val*=prim[id];
            }
            else{
                goto flag;
            }
        }
    }
    flag:
    return;
}

int main(){
    int T;scanf("%d",&T);
    init();
    while(T--){
        scanf("%lld",&N);
        max_cnt=0;
        min_val=INF;
        dfs(0,63,1,1);
        printf("%lld %lld\n",min_val,max_cnt);
    }
    return 0;
}
