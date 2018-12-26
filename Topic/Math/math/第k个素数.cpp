#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<utility>
using namespace std;
const int MAXN=1e5+7;
const int MAXM=1e7+7;
int p[MAXN],tot=1;;
bool isprime[MAXM];
long long hasPI[MAXM];
map<long long ,long long >Map;
struct node{
	long long x,y;
	bool operator<(const node&other)const{
		return x<other.x;
	}
};
map<node,long long >Hash;
void init(){
	memset(isprime,-1,sizeof(isprime));
	for(int i=2;i<MAXM;++i){
		if(isprime[i]){
			p[tot++]=i;
			for(int j=2*i;j<MAXM;j+=i){
				isprime[j]=0;
			}
		}
		hasPI[i]=tot;
		if(tot+1==MAXM)break;
	}
}
long long phi(long long m,long long b){
	node t;t.x=m,t.y=b;
	if(Hash[t])return Hash[t];//记忆化
	if(b==0)return m;
	long long x=phi(m,b-1)-phi(m/p[b],b-1);
	return Hash[t]=x;
}
long long pi(long long m){
	if(m<MAXM)return hasPI[m];//预处理
	if(Map[m])return Map[m];//记忆化
	long long y=sqrt(m)-1;
	if(m==0)return 0;
	if(m==1)return 1;
	long long x=phi(m,pi(y))+pi(y);
	return Map[m]=x;
}
int main(){
	long long m,n;
	init();
	scanf("%lld",&m);
	printf("%lld\n",pi(m));
	return 0;
}
