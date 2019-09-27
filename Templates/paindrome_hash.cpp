#include<cstdio>
#include<cstring>
typedef unsigned long long ull;
const int MAXN=1007;
const ull base=1e7+7;
const ull mod=1e9+7;
char s[MAXN];
char t[MAXN*2];int len;
ull inv(ull x,ull p){
    return x==1?1:(p-p/x)*inv(p%x,p)%p;
}

bool isok(int x){//是否存在长度为x的字符串
    ull power=1;
    ull t_power=1;
    ull base_inv=inv(base,mod);
    int size=(x+1)/2;
    for(int i=0;i<=x/2;++i){
        power=power*base%mod;
        if(i==x/2-1)t_power=power;
    }
    ull val0=0,val1=0;
    for(int i=0;i<=x/2;++i)val0=(val0*base+t[i])%mod;
    for(int i=x-1;i>=x/2;--i)val1=(val1*base+t[i])%mod;

    if(val0==val1)return true;
    for(int i=x;i<2*len+1;++i){
        val0=((val0*base+t[i-size+1]-power*t[i-2*size+1])%mod+mod)%mod;
        val1=(((val1-t[i-size])*base_inv%mod+t[i]*t_power%mod)%mod+mod)%mod;
        if(val0==val1)return true;
    }
    return false;
}

int main(){
    scanf("%s",s);
    len=strlen(s);
    int top=0;
    for(int i=0;i<2*len+1;++i){
        if(i%2==0)t[top++]='#';
        else t[top++]=s[i/2];
    }
    t[top++]='\0';//len=2*len+1
    int lo=0,hi=len+1;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(isok(2*mid+1))lo=mid;
        else hi=mid;
    }
    printf("%d\n",lo);
    return 0;
}
