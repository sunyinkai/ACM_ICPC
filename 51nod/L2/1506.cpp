//tag: trick,heap,greedy
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=5e5+7;
struct node{
    char val;
    int id;
    bool operator<(const node&other)const{
        return val>other.val||(val==other.val&&id>other.id);
    }
};

priority_queue<node>q;
char s[MAXN];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;++i){
        q.push(node{s[i],i});
    }
    int x=-1,y=-1;
    for(int i=0;i<len;++i){
        node u=q.top();q.pop();
        if(s[i]==u.val){
            continue;
        }else{
            x=i;
            y=u.id;
            while(!q.empty()){
                node u=q.top();q.pop();
                if(u.val==s[y])y=u.id;
            }
            break;
        }
    }

    if(x!=-1){
        swap(s[x],s[y]);
    }else{
        auto have_repeat=[=]()->bool{
            int visit[500];
            memset(visit,0,sizeof(visit));
            for(int i=0;i<len;++i){
                visit[s[i]]++;
                if(visit[s[i]]>=2)return true;
            }
            return false;
        };
        if(have_repeat()){
            //do nothing
        }else{
            swap(s[len-1],s[len-2]);
        }
    }
    printf("%s\n",s);
    return 0;
}
