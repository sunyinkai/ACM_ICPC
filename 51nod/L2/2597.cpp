//tag: logic
#include<cstdio>
int power[31];
int solve(int n,int m){
    if(n==1){
        return m==1?1:0;
    }
    if(m>power[n-2])return -solve(n-1,m-power[n-2]);
    else return solve(n-1,m);
}
int main(){
    int n,m;
    power[0]=1;
    for(int i=1;i<=30;++i)power[i]=power[i-1]*2;
    while(~scanf("%d%d",&n,&m)){
        int val=solve(n,m);
        printf("%c\n",val==1?'A':'B');
    }
    return 0;
}
