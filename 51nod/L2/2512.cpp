#include<cstdio>
int main(){
    long long val;
    scanf("%lld",&val);
    int cnt[10]={0};

    while(val){
        cnt[val%10]++;
        val/=10;
    }

    bool hasAns=false;
    for(long long x=1;x<=1e10;x*=2){
        long long tmp=x;
        int cnt_2[10]={0};
        while(tmp){
            cnt_2[tmp%10]++;
            tmp/=10;
        }
        int isok=1;
        for(int k=0;k<10;++k){
            if(cnt[k]!=cnt_2[k])isok=0;
        }
        if(isok)hasAns=true;
    }
    printf(hasAns?"true\n":"false\n");
    return 0;
}
