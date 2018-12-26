#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=5e5+7;
const int INF=1e9+7;
char Ma[MAXN*2];int Mp[MAXN*2];
//abaaba
//Mp[i]-1:回文串长度
//$ # a # b # a # a # b # a #
//1 1 2 1 4 1 2 7 2 1 4 1 2 1
//第i个字符下标为2*(i+1) i从0开始
int sum[MAXN],a[MAXN];
bitset<MAXN>Left,Right;
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
	//计算前缀和
	//printf("%s\n",Ma);
	sum[0]=0;
	for(int i=1;i<l;++i){
		//printf("%d ",Mp[i]);
		if(Ma[i]>='a'&&Ma[i]<='z')sum[i]=sum[i-1]+a[Ma[i]-'a'];
		else sum[i]=sum[i-1];
	}

	//枚举以i为回文中心
	int res=0;
	Left.reset();Right.reset();
	for(int i=1;i<l;++i){
		//以i为回文串中心
		if(i-Mp[i]==0&&i+Mp[i]!=l){
			int rt=i+Mp[i]-1;
			Right[rt]=1;
			res=max(res,sum[rt]-sum[0]);
		}else if(i+Mp[i]==l&&i-Mp[i]!=0){
			int lt=i-Mp[i]+1;
			Left[lt]=1;
			res=max(res,sum[l-1]-sum[lt]);
		}//单个考虑
	}
	//寻找拼接重合点,两个数组中相同的数的个数
	//cout<<"Left:"<< Left<<endl;
	//cout<<"Right:"<<Right<<endl;

	Left=Left&Right;
	if(Left.any()){
		res=max(res,sum[l-1]-sum[0]);
	}
	printf("%d\n",res);
}

char s[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		for(int i=0;i<26;++i)scanf("%d",&a[i]);
		scanf("%s",s);
		int len=strlen(s);
		Manacher(s,len);

	}
	return 0;
}
