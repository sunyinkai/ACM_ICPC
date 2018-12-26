#include<cstdio>
#include<cstring>
const int MAXN=10007;
void calc(int a[],int num,int flag){
	for(int i=2;i*i<=num;++i){
		while(num&&num%i==0){
			a[i]+=flag;
			num/=i;
		}
	}
	if(num>=2)a[num]+=flag;
}
int x[MAXN],y[MAXN];

int main(){
	int p,q,r,s;
	while(~scanf("%d%d%d%d",&p,&q,&r,&s)){
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		for(int i=p-q+1;i<=p;++i)
			calc(x,i,1);
		for(int i=1;i<=q;++i)
			calc(x,i,-1);
		for(int i=r-s+1;i<=r;++i)
			calc(y,i,1);
		for(int i=1;i<=s;++i)
			calc(y,i,-1);
		double res=1.0;
		for(int i=2;i<=10000;++i){
			if(x[i]||y[i]){
				int cnt=x[i]-y[i];
				if(cnt>0){
					for(int j=0;j<cnt;++j)res*=i;
				}else{
					cnt=-cnt;
					for(int j=0;j<cnt;++j)res/=i;
				}
			}
		}
		printf("%.5f\n",res);
	}
	return 0;
}
