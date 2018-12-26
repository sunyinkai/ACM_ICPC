#include<cstdio>
#include<cstring>
int main(){
	long long N,Q;scanf("%lld%lld",&N,&Q);
	while(Q--){
		long long x,y;scanf("%lld%lld",&x,&y);
		long long res=0;
		if((x+y)%2==0){//front
			if(N%2==0){
				res=(long long)N/2*(x-1)+(y+1)/2;
			}else{
				int tmp=(x-1)/2;
				res=(long long)tmp*(N/2+(N+1)/2);

				if(x%2){//odd
					res+=(y+1)/2;
				}else{//even
					res+=(N+1)/2;
					res+=y/2;
				}
			}
		}else{//back
			if(N%2==0){
				res=(long long)N*N/2+(long long)N/2*(x-1)+(y+1)/2;
			}else{
				long long N2=(long long)N*N;
				res=(N2+1)/2;
				long long tmp=(x-1)/2;
				res+=(long long)tmp*(N/2+(N+1)/2);
				if(x%2){//odd
					res+=y/2;
				}else{//even
					res+=N/2;
					res+=(y+1)/2;
				}
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
