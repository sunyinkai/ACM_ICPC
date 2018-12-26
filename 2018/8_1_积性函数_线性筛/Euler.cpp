#include<cstdio>
#include<cstring>
int flag[100],tot,prime[100],phi[100];

void euler(int n){ 
	tot=0;
	memset(flag,0,sizeof(flag));
	for(int i=2;i<=n;++i){ 
		if(!flag[i]){ 
			prime[tot++]=i;
			phi[i]=i-1;//i为质数
		}
		for(int j=0;i*prime[j]<=n;++j){ 
			flag[i*prime[j]]=true;
			printf("j=%d,flag[%d*%d]=%d\n",j,i,prime[j],flag[i*prime[j]]);
			if(i%prime[j]){ //互质,gcd(i,prime[j])=1;
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}else{ //p|n phi[n*p]=phi[n]*(p);
				phi[i*prime[j]]=phi[i]*prime[j];
				printf("break\n");
				break;
			}
		}
	}
}
int main(){ 
	euler(12);
	return 0;
}
