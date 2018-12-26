#include<cstdio>
int main(){
	for(int i=0;i<=200;++i){
		for(int j=0;j<=200;++j){
			for(int k=0;k<=200;++k){
				int val=i^j^k;
				int isok=0;bool hasAns=true;
				for(int to=0;to<=val;++to){
					int num=val^to;
					if((num^i)<=i||(num^j)<=j||(num^k)<=k){
						
					}else isok=to,hasAns=false;
				}
				if(!hasAns){
					printf("%d %d %d val=%d, to=%d\n",i,j,k,val,isok);
				}
			}
		}
	}
	return 0;
}
