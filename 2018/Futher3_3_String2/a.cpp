#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=5e5+7;
int sum[MAXN],val[26];
char Ma[MAXN*2];int Mp[MAXN*2];
//abaaba
//Mp[i]-1:回文串长度
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
		printf("Mp[i]=%d\n",Mp[i]);
	}
	//Mp[i]-1:回文串长度
}

char s[MAXN];
int len;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		for(int i=0;i<26;++i)scanf("%d",&val[i]);
		scanf("%s",s);
		len=strlen(s);
		sum[0]=0;
		Manacher(s,len);
	}
	return 0;
}

