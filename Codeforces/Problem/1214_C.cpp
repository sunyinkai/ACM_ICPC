#include<cstdio>
#include<stack>
using namespace std;
const int MAXN=2e5+7;
char s[MAXN];
char remain[MAXN];
int main(){
    int N;scanf("%d",&N);
    scanf("%s",s);
    stack<char>st;
    for(int i=0;i<N;++i){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            char ch=st.top();
            if(ch=='('&&s[i]==')'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    }
    int top=0;
    while(!st.empty()){
        remain[top++]=st.top();
        st.pop();
    }
    if((top==2&&remain[0]!=remain[1])||top==0)printf("Yes\n");
    else printf("No\n");
    return 0;
}
