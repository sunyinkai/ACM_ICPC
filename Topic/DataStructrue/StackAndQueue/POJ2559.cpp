#include<cstdio>
#include<stack>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int left[MAXN],right[MAXN];
int main(){
    int N;
    while(~scanf("%d",&N)&&N){
        for(int i=1;i<=N;++i)
            scanf("%d",&a[i]);

        a[N+1]=a[0]=-1;//边界
        stack<int>st;//维护一个单调递增的栈
        while(!st.empty())st.pop();
        for(int i=1;i<=N+1;++i){
            if(st.empty()){st.push(i);continue;}
            if(a[i]>=a[st.top()])st.push(i);
            else{
                while(!st.empty()&&a[i]<a[st.top()]){
                    right[st.top()]=i;
            //        printf("right[%d]:%d\n",st.top(),i);
                    st.pop();
                }
                st.push(i);
            }
        }

        while(!st.empty())st.pop();
        for(int i=N;i>=0;--i){
            if(st.empty()){st.push(i);continue;}
            if(a[i]>=a[st.top()])st.push(i);
            else{
                while(!st.empty()&&a[i]<a[st.top()]){
                    left[st.top()]=i;
             //       printf("left[%d]:%d\n",st.top(),i);
                    st.pop();
                }
                st.push(i);
            }
        }
        long long ans=0;
        for(int i=1;i<=N;++i){
            long long val=(long long)a[i]*(right[i]-left[i]-1);
            if(val>ans)ans=val;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
