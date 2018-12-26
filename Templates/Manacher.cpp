#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=5e5+7;
char Ma[MAXN*2];int Mp[MAXN*2];
//abaaba
//Mp[i]-1:回文串长度,Mp[i]:回文半径
//第i个字符的位置在2*(i+1),i从0开始编号
//$ # a # b # a # a # b # a #
//1 1 2 1 4 1 2 7 2 1 4 1 2 1

void Manacher(char s[],int len){
	int l=0;
	Ma[l++]='$';
	Ma[l++]='#';
	for(int i=0;i<len;++i){
		Ma[l++]=s[i];
		Ma[l++]='#';
	}
	Ma[l]=0;
	int mx=0,id=0;
	for(int i=0;i<l;++i){
		Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
		while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
		if(i+Mp[i]>mx){
			mx=i+Mp[i];
			id=i;
		}
	}
}

char s[MAXN];
int p[MAXN];
int a[MAXN];
inline int lowbit(int i){
	return i&-i;
}

int len;
long long sum(int x){
	long long res=0;
	while(x){
		res+=a[x];
		x-=lowbit(x);
	}
	return res;
}
void add(int p,int x){
	while(p<=len){
		a[p]+=x;
		p+=lowbit(p);
	}
}
vector<int>g[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		len=strlen(s);
		Manacher(s,len);
		memset(a,0,sizeof(a));
		for(int i=0;i<MAXN;++i)g[i].clear();
		int tot=0;
		//i<j
		//j-i<=p[i]
		//j-i<=p[j]
		//---->
		// i<j<=p[i]+i;
		//i>=j-p[j]

		for(int i=0;i<2*len+2;++i){
			if(Ma[i]>='a'&&Ma[i]<='z'){
				//Mp[i]-1回文串长度
				p[++tot]=Mp[i]/2-1;//回文半径
				g[tot-p[tot]].push_back(tot);	
			}
		}

		long long ans=0;
		for(int i=1;i<=tot;++i){
			int len=g[i].size();
			for(int j=0;j<len;++j)
				add(g[i][j],1);
			ans+=sum(min(p[i]+i,tot))-sum(i);
		}
		printf("%lld\n",ans);
	}

	return 0;
}

