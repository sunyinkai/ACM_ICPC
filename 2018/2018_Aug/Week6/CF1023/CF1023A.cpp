#include<cstdio>
#include<cstring>
const int MAXN=2e5+7;
char s[MAXN],t[MAXN];
int main(){
	int N,M;scanf("%d%d",&N,&M);
	scanf("%s%s",s,t);
	bool has=false;
	for(int i=0;i<N;++i){
		if(s[i]=='*')has=true;
	}
	if(N>M+1){printf("NO\n");}
	else if(N==M+1){
		if(has){
			int i=0,ii=0,j=N-1,jj=M-1;
			while(s[i]==t[ii])++i,++ii;
			while(s[j]==t[jj])--j,--jj;
			if(i==j)printf("YES\n");
			else printf("NO\n");
		}else{
			printf("NO\n");
		}
	}else if(N==M){
			if(has){
				int i=0,ii=0,j=N-1,jj=M-1;
				while(s[i]==t[ii])++i,++ii;
				while(s[j]==t[jj])--j,--jj;
				if(i==j)printf("YES\n");
				else printf("NO\n");
			}else{
				if(strcmp(s,t)==0)printf("YES\n");
				else printf("NO\n");
			}
	}else{
			int i=0,ii=0,j=N-1,jj=M-1;
			while(s[i]==t[ii])++i,++ii;
			while(s[j]==t[jj])--j,--jj;
			if(i==j)printf("YES\n");
			else printf("NO\n");
	}
	return 0;
}
