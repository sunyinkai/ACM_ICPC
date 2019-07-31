//tag: stack
//找到01矩阵中最大全1矩形的面积 51nod1158
//O(N)找到第一个比a[i]小的/大的数

#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=507;
int up[MAXN];
int M,N;//N行M列

int solve(){
    int stk[MAXN],top=0;
    int right[MAXN],left[MAXN];
    up[M+1]=-1,up[0]=-1;//方便最后所有元素出栈

    for(int i=1;i<=M+1;++i){
        if(top==0)stk[top++]=i;
        else{
            while(top>0 && up[i]<up[stk[top-1]]){
                --top;
                right[stk[top]]=i-1;
            }
            stk[top++]=i;
        }
    }
    
    top=0;
    for(int i=M;i>=0;--i){
        if(top==0)stk[top++]=i;
        else{
            while(top>0&&up[i]<up[stk[top-1]]){
                --top;
                left[stk[top]]=i+1;
            }
            stk[top++]=i;
        }
    }

    int ans=0;
    for(int i=1;i<=M;++i){
        ans=max(ans,(right[i]-left[i]+1)*up[i]);
    }
    return ans;
}

int main(){
    scanf("%d%d",&M,&N);
    int ans=0;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            int x;scanf("%d",&x);
            if(x==1)up[j]+=1;
            else up[j]=0;
        }
       //up为高度
       ans=max(solve(),ans);
    }
    printf("%d\n",ans);
}
