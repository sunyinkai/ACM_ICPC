#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const int MAXN=4e4+7;
const ull mod=123;
int m,n,pos;
char s[MAXN];
ull H[MAXN],xp[MAXN];
ull Hash[MAXN];
int Rank[MAXN];
int cmp(const int &a,const int &b){
	return Hash[a]<Hash[b]||(Hash[a]==Hash[b]&&a<b);
}
bool isok(int L){
	int c=0;
	pos=-1;
	for(int i=0;i<n-L+1;++i){
		Rank[i]=i;
		Hash[i]=H[i]-H[i+L]*xp[L];//以i开头长度为L的Hash值
	}
	sort(Rank,Rank+n-L+1,cmp);
	for(int i=0;i<n-L+1;++i){
		if(i==0||Hash[Rank[i]]!=Hash[Rank[i-1]])c=0;
		if(++c>=m)pos=max(pos,Rank[i]);
	}
	return pos>=0;
}
int main(){
	while(scanf("%d",&m)&&m){
		scanf("%s",s);
		int len=strlen(s);
		n=len;
		H[n]=0;
		for(int i=len-1;i>=0;--i)H[i]=H[i+1]*mod+(s[i]-'a');
		xp[0]=1;
		for(int i=1;i<=len;++i)xp[i]=xp[i-1]*mod;// xp[i] x^p

		int lo=0,hi=len+1;
		while(hi-lo>1){//二分长度
			int mid=(hi+lo)/2;
			if(isok(mid))lo=mid;
			else hi=mid;
		}
		if(lo==0)printf("none\n");
		else{
			isok(lo);
			printf("%d %d\n",lo,pos);
		}
	}

	return 0;
}
