#include<cstdio>
#include<cstring>
const int MAXN=1e5+5;
char text[MAXN],pattern[MAXN],next[MAXN];
int n,m;
void getNext(){
    int i=0,j=-1;
    next[0]=-1;
    while(i<m){
        if(j==-1||pattern[i]==pattern[j]){
            ++i,++j;
            next[i]=j;
        }
        else j=next[j];
    }
}
int xunhuan;
int point[MAXN];
void  KMP(void){
    getNext();
	xunhuan=m-next[m];
	memset(point,0,sizeof(point));
	int ans=0;
    int i=0,j=0;
    while(i<n){
        if(j==-1||text[i]==pattern[j]){
            ++i,++j;
        }
        else
            j=next[j];
        if(j==m){
			printf("i=%d\n",i);
			point[i-m]=1;
			++ans;
			j=next[j];
        }
    }
}
void solve(){
	for(int i=0;i<n;++i){
		printf("%d ",point[i]);
	}
	printf("\n");
	
}
int main(void){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%s%s",text,pattern);
		n=strlen(text);
		m=strlen(pattern);
		KMP();
		solve();
		printf("m=%d,next[m]=%d,xunhuan=%d\n",m,next[m],xunhuan);
    }
    return 0;
}
