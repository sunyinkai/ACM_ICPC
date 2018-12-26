#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef unsigned long long ull;
const int MAXN=4e4+7;
const ull mod=12345;
int m,n,pos;
char s[MAXN];
ull H[MAXN],xp[MAXN];

ull Hash[MAXN];
bool isok(int L){
	map<ull,int>mp;
	map<ull,int>fp;
	for(int i=0;i<n-L+1;++i){
		Hash[i]=H[i]-H[i+L]*xp[L];//以i开头，长度为L的子串的Hash值
		mp[Hash[i]]++;
		fp[Hash[i]]=i;//保证了相同hash值下标最靠后
	}
	bool hasAns=false;
	auto resVal=mp.begin();
	for(auto it=mp.begin();it!=mp.end();++it){
		if(it->second>=m){
			resVal=it;
			pos=fp[it->first];
			hasAns=true;
		}
	}
	return hasAns;
}
int main(){
	while(scanf("%d",&m)&&m){
		scanf("%s",s);
		int len=strlen(s);
		n=len;
		H[len]=0;
		for(int i=len-1;i>=0;--i)H[i]=H[i+1]*mod+(s[i]-'a');
		xp[0]=1;
		for(int i=1;i<=len;++i)xp[i]=xp[i-1]*mod;// xp[i] x^p

		int lo=0,hi=len;
		while(hi-lo>1){//二分长度
			int mid=(hi+lo)/2;
			if(isok(mid))lo=mid;
			else hi=mid;
		}
		if(lo==0)printf("none\n");
		else{
			printf("%d %d\n",lo,pos);
		}
	}

	return 0;
}
