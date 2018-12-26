#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAXN=8000*2+2;
int col[MAXN<<4];
map<int,int>mp;

struct node{ 
	int l,r,col;
	bool operator <(const node&other)const{ 
		return l<other.l||(l==other.l&&r<other.r);
	}
}no[MAXN];

int top;
void pushDown(int rt){ 
	if(col[rt]!=-1){ 
		col[rt<<1]=col[rt<<1|1]=col[rt];
		col[rt]=-1;
	}
}

void update(int L,int R,int c,int l,int r,int rt){ 
	if(L<=l&&R>=r){ 
		col[rt]=c;
		return ;
	}
	pushDown(rt);
	int m=(l+r)/2;
	if(L<=m)update(L,R,c,lson);
	if(R>m)update(L,R,c,rson);
}

void query(int l,int r,int rt){ 
	if(col[rt]!=-1){
		no[top].l=l;
		no[top].r=r;
		no[top].col=col[rt];
		top++;
		return ;
	}
	if(l==r)return ;
	int m=(l+r)/2;
	query(lson);
	query(rson);
}

int main(){ 
	int N;
	while(~scanf("%d",&N)){ 
		memset(col,-1,sizeof(col));
		top=0;
		mp.clear();

		for(int i=0;i<N;++i){ 
			int l,r,c;
			cin>>l>>r>>c;
			update(2*l+1,2*r+1,c,1,2*8000+1,1);
		}
		//print(1,2*N+1,1);
		query(1,2*8000+1,1);
		
		sort(no,no+top);
		no[top].col=-1;
		for(int i=0;i<top;++i){ 
			mp[no[i].col]++;
			while(no[i].col==no[i+1].col&&i<top)++i;

		}

		for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){ 
			cout<<it->first<<" "<<it->second<<endl;
		}
		cout<<endl;
	}
	return 0;
}
