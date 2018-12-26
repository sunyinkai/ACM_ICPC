#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

//问目标串里出现了几个模式串

//Trie图
const int MAXN=5e5+7;
struct Trie{ 
	//根节点为0

	int ch[MAXN][26],fail[MAXN],end[MAXN];
	int root,tot;
	Trie(){ //init
		tot=1;
		root=0;
		memset(ch,0,sizeof(ch));
		memset(fail,0,sizeof(fail));
	}

	void insert(char * buf){ 
		int len=strlen(buf);
		int u=root;
		for(int i=0;i<len;++i){ 
			if(!ch[u][buf[i]-'a'])
				ch[u][buf[i]-'a']=tot++;
			u =ch[u][buf[i]-'a'];
		}
		end[u]++;
	}

	void build(){ 
		queue<int>Q;
		fail[root]=root;
		for(int i=0;i<26;++i)
			if(!ch[root][i])
				ch[root][i]=root;
			else{ 
				fail[ch[root][i]]=root;
				Q.push(ch[root][i]);
			}
		while(!Q.empty()){ 
			int u=Q.front();Q.pop();
			for(int i=0;i<26;++i){ 
				int v=ch[u][i];
				if(!v)//补全
					ch[u][i]=ch[fail[u]][i];
				else { 
					fail[v]=ch[fail[u]][i];
					Q.push(v);
				}
			}
		}
	}

	int query(char* buf){ 
		int len=strlen(buf);
		int u=root;
		int res=0;
		
		for(int i=0;i<len;++i){ 
			u=ch[u][buf[i]-'a'];
			int temp=u;
			while(temp!=root){ 
				res+=end[temp];
				end[temp]=0;
				temp=fail[temp];
			}
		}
		return res;
	}
};

int main(){ 
	return 0;
}
