//tag: sliding_window
#include<cstdio>
const int MAXN=1e6+7;
int q1[MAXN],q2[MAXN];
int a[MAXN];
//维护一个单调递增和单调递减的队列
int main(){
    int N,M,C;
    scanf("%d%d%d",&N,&M,&C);
    int ans=0;
    int s1=0,e1=0;//维护单调增1
    int s2=0,e2=0;//维护单调减2
    for(int i=1;i<=N;++i){
        scanf("%d",&a[i]);
        //初始化
        if(i==1){
            q1[e1++]=1;//1
            q2[e2++]=1;//2
            continue;
        }

        //1
        while(e1>s1 && a[i]<a[q1[e1-1]]){
            --e1;
        }
        q1[e1++]=i;

        //2
        while(e2>s2 && a[i]>a[q2[e2-1]]){
            --e2;
        }
        q2[e2++]=i;

        //1
        while(q1[s1]+M<=i)++s1;
        //2
        while(q2[s2]+M<=i)++s2;

        if(i>=M){
            ans+=(a[ q2[s2] ]-a[ q1[s1] ] <= C);
        }
    }
    printf("%d\n",ans);
    return 0;
}
