#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN=1e4+7;
const int INF=1e9+7;
char  s[MAXN];
int cnt[500];
struct node{
	int id,cost;
	bool operator<(const node&other)const{
		return cost<other.cost||((cost==other.cost)&&id<other.id);
	}
}no[MAXN];

int main(){
	int N,K;scanf("%d%d",&N,&K);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;++i)
		cnt[(int)s[i]]++;
	for(int i='0';i<='9';++i)
		if(cnt[i]>=K){
			printf("0\n");
			printf("%s\n",s);
			return 0;
		}

	string t;int res=INF;
	for(int k='0';k<='9';++k){
		for(int i=0;i<len;++i){
			no[i].id=i;
			no[i].cost=abs(s[i]-k);
		}
		int ans=0;
		string tmp="";
		for(int i=0;i<len;++i)tmp+=s[i];
		sort(no,no+len);
		for(int i=0;i<K;++i){
			ans+=no[i].cost;
			tmp[no[i].id]=k;
		}
		if(ans<=res){
			if(ans<res)res=ans,t=tmp;
			else t=min(t,tmp);
		}
	}
	printf("%d\n",res);
	cout<<t<<endl;
	return 0;
}

