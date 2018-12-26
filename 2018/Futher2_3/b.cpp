#include<cstdio>
#include<map>
using namespace std;
int a[22];
long long gcd(long long a,long long b){ 
	return b?gcd(b,a%b):a;
}
long long fac[21];
void init(){ 
	fac[0]=1;
	for(int i=1;i<=20;++i){ 
		fac[i]=fac[i-1]*i;
	}
}

int main(){ 
	int T;scanf("%d",&T);
	init();
	while(T--){ 
		map<int,int>mp,tp;
		mp.clear(),tp.clear();
		int P,N,M;
		scanf("%d%d%d",&P,&N,&M);
		for(int i=0;i<M;++i){ 
			scanf("%d",&a[i]);
			mp[a[i]]++;
		};//A
		for(int i=M;i<M+N;++i){ 
			a[i]=0;
			mp[a[i]]++;//B
		}

		long long fenmu=0,fenzi=0;
		for(int i=0;i<(1<<(M+N));++i){ 
			int cntA=0,cntB=0;
			int res=0;
			for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it)tp[it->first]=it->second;

			for(int j=0;j<M+N;++j){ 
				if(i&(1<<j)){ 
					if(a[j])++cntB,res+=a[j];
					else ++cntA;
					tp[a[j]]--;
				}
			}

			if(cntB-cntA==1||((cntA+cntB==N+M)&&(cntA+1>=cntB))){ 
				if(res>=P){ 
					long long tmp=fac[cntB]*fac[N+M-cntA-cntB]/fac[N];
					for(map<int,int>::iterator it=tp.begin();it!=tp.end();++it)
						if(it->first!=0)tmp/=fac[it->second];
					fenzi+=tmp;
				}
			}
		}

		if(fenzi==0)printf("0/1\n");
		else{ 
			fenmu=fac[N+M]/fac[N];
			for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){ 
				if(it->first==0)continue;
				long long res=it->second;
				fenmu/=fac[res];
			}
			printf("fenzi=%lld,fenmu=%lld\n",fenzi,fenmu);
			long long val=gcd(fenzi,fenmu);
			printf("%lld/%lld\n",fenzi/val,fenmu/val);
		}
	}
	return 0;
}
