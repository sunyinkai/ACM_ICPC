#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int MAXN=1e6+7,MAXM=1e6+7;
const int INF=1e9+7;

int a[MAXM],b[MAXM],c[MAXM];
int dis0[MAXN],dis2[MAXN],done[MAXN];
int N,M;
vector<P>G[MAXN];

//ctrl + D EOF
//不能关闭同步
//只能读入int
const int BUF_SIZE=40960;
struct f {
    int cur, eof;
    char buf[BUF_SIZE];
    char next_char() {
        if (cur == BUF_SIZE) {
            if (eof) return -1;
            int bytes = fread(buf, 1, BUF_SIZE, stdin);
            if (bytes < BUF_SIZE) {
                memset(buf + bytes, -1, BUF_SIZE - bytes);
                buf[bytes] = -1;
                eof = 1;
            }
            cur = 0;
        }
        return buf[cur++];
    }
    int next_int() {
        int x = 0;
        char ch = next_char();
        while (ch < '0' || ch > '9') {
            if (ch == -1) return 0;
            ch = next_char();
        }
        while (ch >= '0' && ch <= '9') {
            x = x*10 + ch - '0';
            ch = next_char();
        }
        return x;
    }
} IO = {BUF_SIZE,};

void dijkstra(int* d,int s){
	for(int i=1;i<=N;++i)d[i]=INF,done[i]=0;
	d[s]=0;
	priority_queue<P,vector<P>,greater<P> >q;
	q.push(P(0,s));
	while(!q.empty()){
		P p=q.top();q.pop();
		int u=p.second;
		if(done[u])continue;
		done[u]=1;
		d[u]=p.first;
		int len=G[u].size();
		for(int i=0;i<len;++i){
			int v=G[u][i].second;
			if(d[v]>d[u]+G[u][i].first){
				d[v]=d[u]+G[u][i].first;
				q.push(P(d[v],v));
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int T;T=IO.next_int();
	while(T--){
		N=IO.next_int();M=IO.next_int();
		for(int i=0;i<M;++i)a[i]=IO.next_int(),b[i]=IO.next_int(),c[i]=IO.next_int();
		for(int i=1;i<=N;++i)G[i].clear();
		for(int i=0;i<M;++i){
			G[a[i]].push_back(P(2-c[i],b[i]));
			G[b[i]].push_back(P(2-c[i],a[i]));
		}
		dijkstra(dis2,N);

		for(int i=1;i<=N;++i)G[i].clear();
		for(int i=0;i<M;++i){
			if(c[i]<=1){
				G[a[i]].push_back(P(1-c[i],b[i]));
				G[b[i]].push_back(P(1-c[i],a[i]));
			}
		}
		dijkstra(dis0,1);

		int res=INF;
		for(int i=1;i<=N;++i){
			res=min(res,dis0[i]+dis2[i]);
		}
		printf("%d\n",res);
	}
	return 0;
}
