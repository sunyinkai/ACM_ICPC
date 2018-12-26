#include<cstdio>
#include<cstring>
const int MAXN=1e6+7;
char s[MAXN];
int R[MAXN],B[MAXN];
int cnt0=0,cnt2=0;
int main(){
	int N,Q;scanf("%d%d",&N,&Q);
	scanf("%s",s+1);
	for(int i=1;i<=N;++i){
		if(s[i]=='R')R[++cnt0]=i;
		else B[++cnt2]=i;
	}
	while(Q--){
		char s[2];int num;
		scanf("%s%d",s,&num);
		if(s[0]=='R'){
			if(num>cnt0)printf("-1\n");
			else printf("%d\n",R[num]);
		}else{
			if(num>cnt2)printf("-1\n");
			else printf("%d\n",B[num]);
		}
	}
	return 0;
}

