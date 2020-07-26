#include<cstdio>
int main(){
    long long u,v;scanf("%lld%lld",&u,&v);
    if(u==0&&v==0){
        printf("0\n");
        return 0;
    }
    if(u%2!=v%2||u>v){
        printf("-1\n");
        return 0;
    }
    if(u==0){//(u,0)
        printf("2\n%lld %lld\n",v/2,v/2);
        return 0;
    }
    if(v==0){//(0,v)
        printf("-1\n");
        return 0;
    }
    // 1 is ok
    if(u==v){
        printf("1\n");
        printf("%lld\n",u);
        return 0;
    }
    // 2 is ok
    long long t1=(v-u)/2;
    long long t2=t1^u;
    if(t1+t2==v){
        printf("2\n%lld %lld\n",t1,t2);
        return 0;
    }
    //3 is ok
    printf("3\n");
    printf("%lld %lld %lld\n",u,(v-u)/2,(v-u)/2);
    return 0;
}
