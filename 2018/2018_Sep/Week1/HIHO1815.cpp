//动态求全局第K大，
//logN*logN二分+树状数组

#include<cstdio>
#include<cstring>
#include<ctype.h>
const int MAXN=1e6+7;
int bit[MAXN],cnt[MAXN];

inline int lowbit(int i){
	return i&-i;
}
int N;
inline void  add(int p,int x){
	while(p<MAXN){
		bit[p]+=x;
		p+=lowbit(p);
	}
}
inline int sum(int x){
	int res=0;
	while(x){
		res+=bit[x];
		x-=lowbit(x);
	}
	return res;
}

inline int get(int k){
	int lo=-1,hi=1e6+7;
	while(hi-lo>1){//二分val
		int mid=(hi+lo)/2;
		if(sum(mid)>=k)hi=mid;
		else lo=mid;
	}
	return hi-1;
}
inline int read(){
	char ch;
	while(isspace(ch=getchar()));
	int res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9'){
		res=res*10+ch-'0';
	}
	//printf("res=%d\n",res);
	return res;
}
int main(){
	scanf("%d",&N);
	int num=0;
	while(N--){
		char s[2];int x;
		scanf("%s",s);
		x=read();
		x++;
		if(s[0]=='A'){
			++num;
			cnt[x]++;
			add(x,1);
		}else{
			if(cnt[x]){
				--num;
				cnt[x]--;
				add(x,-1);
			}
		}

		if(num==0){
			printf("0\n");
			continue;
		}
		if(num&1){
			int val=get((num+1)/2);
			printf("%d\n",val);
		}else{
			int all=get(num/2);
			all+=get(num/2+1);
			if(all%2==0)printf("%d\n",all/2);
			else printf("%.1f\n",all*1.0/2);
		}
	}
	return 0;
}
