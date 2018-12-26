#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXN=1e5+7;
int in[MAXN],out[MAXN];
int visit[MAXN];
int tot,head[MAXN];
void init(){ 
	tot=0;
	memset(head,-1,sizeof(head));
}

struct edge{ 
	int to,next;
	int id,ans;
	bool operator<(const edge&other)const{ 
		return id<other.id;
	}
}es[MAXN*6];

void addEdge(int a,int b,int id){ 
	es[tot].id=id;
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

void dfs(int u,int pre){ 
	if(pre!=-1)visit[pre]=1;
	for(int i=head[u];~i;i=es[i].next){ 
		if(visit[i])continue;
		int v=es[i].to;
		int a=u,b=v;
		if(in[a]>out[a]){//a->b
			out[a]++;in[b]++;
			es[i].ans=1;
		}else{ //b->a
			in[a]++;out[b]++;
			es[i].ans=0;
		}
		dfs(v,i);
	}
}
int main(){ 
	int T;scanf("%d",&T);
	while(T--){ 
		int N,M;scanf("%d%d",&N,&M);
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(visit,0,sizeof(visit));
		init();
		for(int i=0;i<M;++i){ 
			int a,b;scanf("%d%d",&a,&b);
			addEdge(a,b,i);	
			addEdge(b,a,i);
		}
		dfs(1,-1);
		sort(es,es+M*2);
		for(int i=0;i<2*M;++i){ 
			printf("%d\n",es[i].ans);
		}
	}
	return 0;
}
