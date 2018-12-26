#include<cstdio>
#include<cstring>
const int MAXN=2e5+7;
int tot,head[MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
struct edge{
	int to,next,weight;
}es[MAXN*2];
void addEdge(int a,int b,int c){
	es[tot].weight=c;
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

int h[MAXN];
int N;
void dfs(int u,int pre){
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		h[v]=h[u]^es[i].weight;
		dfs(v,u);
	}
}

int ch[MAXN*16][2],cnt;
void insert(const int*s){
	int now=0;
	for(int i=31;i>=0;--i){
		int val=s[i];
		if(!ch[now][val])ch[now][val]=++cnt;
		now=ch[now][val];
	}
}
long long query(int x){
	int now=0;
	long long res=0;
	int a[32];
	for(int i=0;i<32;++i){
		a[i]=x%2;
		x/=2;
	}
	for(int i=31;i>=0;--i){
		res*=2;
		if(a[i]&1){//a[i]=1;
			if(ch[now][0])++res,now=ch[now][0];
			else now=ch[now][1];
		}else{
			if(ch[now][1])++res,now=ch[now][1];
			else now=ch[now][0];
		}
	}
	return res;
}

void solve(){
	int s[32];
	cnt=0;
	memset(ch,0,sizeof(ch));

	for(int i=0;i<N;++i){
		int num=h[i];
		for(int j=0;j<32;++j){
			s[j]=num%2;
			num/=2;
		}
		insert(s);
	}
	long long res=0;
	for(int i=0;i<N;++i){
		long long num=query(h[i]);
		if(num>res)res=num;
	}
	printf("%lld\n",res);
}
int main(){
	while(~scanf("%d",&N)){
		init();
		memset(h,0,sizeof(h));
		for(int i=1;i<N;++i){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		dfs(0,-1);
		solve();
	}
	return 0;
}
