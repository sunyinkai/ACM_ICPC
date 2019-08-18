//tag: bfs
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=107;
char s[MAXN][MAXN];
int sx,sy;
queue<int>q;
int visit[MAXN*MAXN];
int N;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

void bfs1(int sx,int sy){
    q.push(sx*N+sy);
    while(!q.empty()){
        int u=q.front();q.pop();
        visit[u]=0;
        int sx=u/N,sy=u%N;
        for(int i=0;i<4;++i){
            int nx=sx+dx[i],ny=sy+dy[i];
            if(nx>=0&&nx<N && ny>=0&&ny<N && s[nx][ny]=='1' && visit[nx*N+ny]==-1){
                visit[nx*N+ny]=0;
                q.push(nx*N+ny);
            }
        }
    }
}

int bfs2(){
    while(!q.empty())q.pop();
    for(int i=0;i<N*N;i++){
        if(visit[i]!=-1){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u=q.front();q.pop();
        int sx=u/N,sy=u%N;
        for(int i=0;i<4;++i){
            int nx=sx+dx[i],ny=sy+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<N&&visit[nx*N+ny]==-1){
                visit[nx*N+ny]=visit[sx*N+sy]+1;
                if(s[nx][ny]=='1'){
                    return visit[sx*N+sy];
                }
                q.push(nx*N+ny);
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%s",s[i]);
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(s[i][j]=='1'){
                sx=i;sy=j;
                break;
            }
        }
    }
    memset(visit,-1,sizeof(visit));
    bfs1(sx,sy);
    int val=bfs2();
    printf("%d\n",val);
    return 0;
}
