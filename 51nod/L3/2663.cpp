//tag: dfs,logic
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

const int MAXN=1007;
char s[MAXN][MAXN];
int cnt[MAXN*MAXN];
int type[MAXN][MAXN];

int tot=1;
int N,M;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};


std::queue<int>q;
int dfs(int x,int y){
    int now_cnt=1;
    type[x][y]=tot;
    while(!q.empty())q.pop();
    q.push(x*M+y);
    while(!q.empty()){
        int u=q.front();q.pop();
        int x=u/M,y=u%M;
        for(int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&s[nx][ny]=='.'&&type[nx][ny]==0){
                ++now_cnt;
                q.push(nx*M+ny);
                type[nx][ny]=tot;
            }
        }
    }
    return now_cnt;
}


int solve(int x,int y){
    int val[4];//类型列表
    int tot=0;
    for(int i=0;i<4;++i){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<M&&s[nx][ny]=='.'){
            val[tot++]=type[nx][ny];
        }
    }
    std::sort(val,val+tot);
    tot=std::unique(val,val+tot)-val;
    int ans=0;
    for(int i=0;i<tot;++i){
        ans+=cnt[val[i]];
    }
    return ans+1;
}

int main(){
    #ifdef DEBUG
    int fd=open("2.in",O_RDONLY);
    int num=dup2(fd,STDIN_FILENO);
    printf("num:%d\n",num);
    #endif
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;++i)
        scanf("%s",s[i]);
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(s[i][j]=='.'&&type[i][j]==0){
                cnt[tot]=dfs(i,j);
                tot++;
            }
        }
    }

    //solve and output
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(s[i][j]=='*'){
                printf("%d",solve(i,j)%10);
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}
