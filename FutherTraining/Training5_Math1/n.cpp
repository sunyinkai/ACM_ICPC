#include<bits/stdc++.h>
using namespace std;
//N/N+N/(N-1)+...
int main(){
	long long N;
	while(~scanf("%lld",&N)){
		long long fenzi=0,fenmu=1,zenshu=N;
		for(int i=2;i<=N;++i){
			long long tmpfenzi,tmpfenmu;
			tmpfenzi=i*fenzi+N*fenmu;
			tmpfenmu=i*fenmu;
			long long res=__gcd(tmpfenzi,tmpfenmu);
			tmpfenzi/=res;
			tmpfenmu/=res;
			zenshu+=tmpfenzi/tmpfenmu;
			fenmu=tmpfenmu;
			fenzi=tmpfenzi%tmpfenmu;
		}
	//	printf("fenzi=%lld,fenmu=%lld\n",fenzi,fenmu);
		if(fenzi==0){
			printf("%lld\n",zenshu);
		}else{
			long long tmpfenmu=fenmu,tmpzenshu=zenshu,spaceCnt=0,spaceCnt2=0;
			while(tmpfenmu){
				spaceCnt++;
				tmpfenmu/=10;
			}
			while(tmpzenshu){
				spaceCnt2++;
				tmpzenshu/=10;
			}
			for(int i=0;i<spaceCnt2+1;++i)printf(" ");
			printf("%lld\n",fenzi);
			printf("%lld ",zenshu);
			for(int i=0;i<spaceCnt;++i)printf("-");printf("\n");
			for(int i=0;i<spaceCnt2+1;++i)printf(" ");
			printf("%lld\n",fenmu);
		}
	}
	return 0;

}
