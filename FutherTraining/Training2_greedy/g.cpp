#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=1e5+7;
struct node{
	string str;
	int s,h;
	bool operator<(const node&other)const{
		return (long long)s*other.h>(long long )other.s*h;
	}
}a[MAXN];
int main(){
	int N;scanf("%d",&N);
	int sumS=0,sumH=0;
	for(int i=0;i<N;++i){
		cin>>a[i].str;
		int sCnt=0,hCnt=0;
		int len=a[i].str.size();
		for(int j=0;j<len;++j){
			if(a[i].str[j]=='s')sCnt++,sumS++;
			else hCnt++,sumH++;
		}
		a[i].s=sCnt,a[i].h=hCnt;
	}
	long long res=0;
	sort(a,a+N);
	for(int i=0;i<N;++i){
		string s=a[i].str;
		int len=s.size();
		for(int i=0;i<len;++i){
			if(s[i]=='s')res+=sumH;
			else sumH--;
		}
	}
	printf("%lld\n",res);
	return 0;
}
