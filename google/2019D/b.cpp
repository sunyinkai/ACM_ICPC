#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1e5+7;
vector<int>val[MAXN],time[MAXN];
int N,G,M;

inline int next_step(int now,char dir){
    if(dir=='C'){
        now=now+1;
        if(now==N+1)now=1;
        return now;
    }else{
        now=now-1;
        if(now==0)now=N;
        return now;
    }
}

void solve(int num,int start,char dir){
    int now=start;
    for(int t=0;t<=M;++t){
        int len=time[now].size();
        if(len==0){
            val[now].push_back(num);
            time[now].push_back(t);
        }
        else if(t>=time[now][0]){
            if(len>0&&t>time[now][0]){
                val[now].clear();
                time[now].clear();
            }
            val[now].push_back(num);
            time[now].push_back(t);
        } 
        now=next_step(now,dir);
    }
}

int count[MAXN];

int main(){
    int T;scanf("%d",&T);
    for(int test=1;test<=T;++test){
        scanf("%d%d%d",&N,&G,&M);

        for(int i=0;i<=N;++i){
            val[i].clear();
            time[i].clear();
        }

        if(M>=N){
            M=N+M%N;
        }
        for(int num=1;num<=G;++num){
            int x;char s[3];
            scanf("%d%s",&x,s);
            solve(num,x,s[0]);
        }
        printf("Case #%d:",test);
        memset(count,0,sizeof(count));
        for(int i=1;i<=N;++i){
            int len=val[i].size();
            for(int j=0;j<len;++j){
                count[val[i][j]]++;
            }
        }
        for(int i=1;i<=G;++i)
            printf(" %d",count[i]);
        printf("\n");
    }
    return 0;
}
