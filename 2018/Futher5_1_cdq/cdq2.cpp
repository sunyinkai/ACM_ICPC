//http://blackops.top/2018/01/04/CDQ%E5%88%86%E6%B2%BB%E5%AD%A6%E4%B9%A0/
//单点修改
//区间询问
//按操作时间分治
//[l,m]区间的更新对[m+1,r]的询问影响只能是更新点在询问范围之内的
//差分计算前缀和

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LC(x) (x<<1)
#define RC(x) ((x<<1)+1)
#define MID(x,y) ((x+y)>>1)
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
typedef pair<int, int> pii;
typedef long long LL;
const double PI = acos (-1.0);
const int N = 500010;
const int M = 500010;
struct query
{
    int x, v, qid, type;
	//位置,值,询问的id,类型
    bool operator< (const query &rhs)const {
        return x < rhs.x || (x == rhs.x && type < rhs.type);
    }
} Q[N + M * 2], temp[N + M * 2];
int ans[N];

void CDQ (int l, int r)//时间已经有序了
{
    if (l >= r)
        return ;
    int mid = MID (l, r);
    CDQ (l, mid);
    CDQ (mid + 1, r);
	//[l,m]的操作序,[m+1,r]的操作序分别增加
    int i = l, j = mid + 1;
    int sz = l, sum = 0;

    while (i <= mid && j <= r){//顺便把序排了
        if (Q[i] < Q[j]){//x代表位置,v代表值,操作顺序
            if (Q[i].type == 1)
                sum += Q[i].v;
            temp[sz++] = Q[i++];
        }
        else{
            if (Q[j].type == 2)//左端点,减
                ans[Q[j].qid] -= sum;
            else if (Q[j].type == 3)//右端点,加
                ans[Q[j].qid] += sum;
            temp[sz++] = Q[j++];
        }
    }

    while (i <= mid)
        temp[sz++] = Q[i++];
    while (j <= r){
        if (Q[j].type == 2)
            ans[Q[j].qid] -= sum;
        else if (Q[j].type == 3)
            ans[Q[j].qid] += sum;
        temp[sz++] = Q[j++];
    }
    for (int i = l; i <= r; ++i)
        Q[i] = temp[i];
}

int main (void)
{
    int n, m, i;
    scanf ("%d%d", &n, &m);
    int tot = 0, qid = 0;
    for (i = 1; i <= n; ++i)
    {
        int v;
        scanf ("%d", &v);
        Q[++tot] = {i, v, 0, 1};
    }
    int ops;
    for (i = 1; i <= m; ++i)
    {
        scanf ("%d", &ops);
        if (ops == 1)
        {
            int x, k;
            scanf ("%d%d", &x, &k);
            Q[++tot] = {x, k, 0, 1};
        }

        else
        {
            int l, r;
            scanf ("%d%d", &l, &r);
            Q[++tot] = {l - 1, 0, ++qid, 2};
            Q[++tot] = {r, 0, qid, 3};
        }
    }
    CDQ (1, tot);
    for (i = 1; i <= qid; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
