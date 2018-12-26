#include<cstdio>
//a...a(n个)*b
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int a,b,d,n;scanf("%d%d%d%d",&a,&b,&d,&n);
		int ans=0;
		if(a*b<10){//a*b<10
			if(a*b==d)ans=n;
			else ans=0;
		}else{//a*b>=10
			if(n==1){
				int t=a*b;
				while(t){if(t%10==d)++ans;t/=10;}
			}
			else if(n==2){
				int t=11*a*b;
				while(t){if(t%10==d)++ans;t/=10;}
			}else{
				int t=11*a*b;
				while(t){if(t%10==d)++ans;t/=10;}
				t=111*a*b;
				if(d==t/100%10)ans+=n+1-3;
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
}
