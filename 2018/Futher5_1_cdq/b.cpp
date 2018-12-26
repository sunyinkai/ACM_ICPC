#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
//需要考虑重复,因为如果a,b一样b在a后面,那么a会比b少
//离散化的技巧

const int MAXN=1e5+7;
const int MAXM=2e5+7;
struct node{
    int id;
    int x,y,z;
    int cnt;
}no[MAXN];
int ans[MAXM],a[MAXM];
int N,M;

inline int lowbit(int i){
    return i&-i;
}
int sum(int i){
    int res=0;
    while(i){
        res+=a[i];
        i-=lowbit(i);
    };
    return res;
}
void add(int i,int x){
    while(i<=M){//这里的等于符号不要忘记
        a[i]+=x;
        i+=lowbit(i);
    }
}

bool cmpy(node a,node b){
    return a.y<b.y||(a.y==b.y&&a.z<b.z);
}

void cdq(int l,int r){
 //   printf("l=%d,r=%d\n",l,r);
    if(l>=r)return;
    int m=(l+r)/2;
    cdq(l,m);
    cdq(m+1,r);//mergesort
    // sort(no+l,no+m+1,[](node &a,node&b){
    //     return a.y<b.y||(a.y==b.y&&a.z<b.z);
    // });
    // sort(no+m+1,no+r+1,[](node &a,node&b){
    //     return a.y<b.y||(a.y==b.y&&a.z<b.z);
    // });
    sort(no+l,no+m+1,cmpy);
    sort(no+m+1,no+r+1,cmpy);
    int lo=l,hi=m+1;
    while(hi<=r){
        while(lo<=m&&no[lo].y<=no[hi].y){
            add(no[lo].z,no[lo].cnt);
            ++lo;
        }
        ans[no[hi].id]+=sum(no[hi].z);
        ++hi;
    }
    for(int j=l;j<lo;++j)add(no[j].z,-no[j].cnt);
}

int res[MAXM];
bool cmpx(node a,node b ) {
    return a.x<b.x||(a.x==b.x&&a.y<b.y)||(a.x==b.x&&a.y==b.y&&a.z<b.z);
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i)ans[i]=0;
    for(int i=1;i<=N;++i)a[i]=0;
    for(int i=1;i<=N;++i){
        no[i].id=i;
        scanf("%d%d%d",&no[i].x,&no[i].y,&no[i].z);
    }
    sort(no+1,no+N+1,cmpx);
    // sort(no+1,no+N+1,[](node&a,node&b){//一维排序
    //     return a.x<b.x||(a.x==b.x&&a.y<b.y)||(a.x==b.x&&a.y==b.y&&a.z<b.z);
    //     });


    int cnt=1,top=0; 
    for(int i=1;i<=N;++i){
        int x=no[i].x,y=no[i].y,z=no[i].z;
        if(x==no[i+1].x&&y==no[i+1].y&&z==no[i+1].z){
            ++cnt;
        }else{
            no[++top]=no[i];
             no[top].cnt=cnt;
             no[top].id=i;
             cnt=1;
        }
    }

    cdq(1,top);
    for(int i=1;i<=top;++i){
        res[ans[no[i].id]+no[i].cnt-1]+=no[i].cnt;
    }

    for(int i=0;i<N;++i){
        printf("%d\n",res[i]);
    }
    return 0;
}