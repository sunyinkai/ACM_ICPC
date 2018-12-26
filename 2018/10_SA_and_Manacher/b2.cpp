#include<cstdio>
#include<cstring>
const int MAXN=4e4+7;;

int sa[MAXN];
int wa[MAXN], wb[MAXN], wv[MAXN], ws[MAXN];
inline bool cmp(int *r, int a, int b, int len)
{
    return r[a] == r[b] && r[a + len] == r[b + len];
}
void SA(char *r, int *sa, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;

    for (i = 0; i < m; i++)
        ws[i] = 0; 
    for (i = 0; i < n; i++)
        ws[x[i] = r[i]]++;
    for (i = 1; i < m; i++)
        ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--)
        sa[--ws[x[i]]] = i; 

    for (j = p = 1; p < n; j <<= 1, m = p)
    {
        for (p = 0, i = n - j; i < n; i++)
            y[p++] = i;
        for (i = 0; i < n; i++)
        {
            if (sa[i] >= j)
                y[p++] = sa[i] - j;
        }

        for (i = 0; i < m; i++)
            ws[i] = 0; 
        for (i = 0; i < n; i++)
            ws[wv[i] = x[y[i]]]++; 
        for (i = 1; i < m; i++)
            ws[i] += ws[i - 1];
        for (i = n - 1; i >= 0; i--)
            sa[--ws[wv[i]]] = y[i]; 
        for (t = x, x = y, y = t, x[sa[0]] = 0, p = i = 1; i < n; i++) 
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
}

int rank[MAXN], height[MAXN];
void Height(char *r, int *sa, int n)
{
    int i, j, k;
    for (i = 1; i <= n; i++)
        rank[sa[i]] = i;
    for (i = k = 0; i < n; height[rank[i++]] = k)
        for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    return;
}

int m,n;
char s[MAXN];
int pos;
bool isok(int L){
    pos=-1;
    int cnt=0;
    bool hasAns=false;
    int tempPos=-1;
    for(int i=1;i<=n;++i){
        if(height[i]>=L){
            ++cnt;
            if(sa[i]>tempPos)tempPos=sa[i];
            if(sa[i-1]>tempPos)tempPos=sa[i-1];
        }else{
            if(cnt>=m-1){
                hasAns=true;
                pos=tempPos;
            }
            cnt=0;
            tempPos=-1;
        }
    }
    return hasAns;
}
int main(){
    while(scanf("%d",&m)&&m){
        scanf("%s",s);
        n=strlen(s);
        SA(s,sa,n+1,'z'+1);
        Height(s,sa,n);
        int lo=0,hi=n+1;
        while(hi-lo>0){
            int mid=(hi+lo)/2;
            if(isok(mid))lo=mid;
            else hi=mid;
        }
        if(lo==0)printf("none\n");
        else{
            isok(lo);
            printf("%d %d\n",lo,pos);
        }
    }
	return 0;
}