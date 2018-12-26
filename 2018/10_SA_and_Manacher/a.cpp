#include<cstdio>
#include<cstring>

const int MAXN=3e5+7;
char a[MAXN],b[MAXN];
char s[MAXN];
int sa[MAXN];

int wa[MAXN], wb[MAXN], wv[MAXN], ws[MAXN];
inline bool cmp(int *r, int a, int b, int len)
{
    return r[a] == r[b] && r[a + len] == r[b + len];
}
//r 字符数组，sa后缀数组，n=strlen(s)+1,m=max(r[i])+1
//sa排名从0开始，sa[0],sa[1],sa[2];
void SA(char *r, int *sa, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++)
        ws[i] = 0; 
    for (i = 0; i < n; i++){
        ws[x[i] = r[i]]++; 
	}
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
//r字符数组，sa后缀数组，n为strlen(s)
void Height(char *r, int *sa, int n)
{
    int i, j, k;
    for (i = 1; i <= n; i++)
        rank[sa[i]] = i;
    for (i = k = 0; i < n; height[rank[i++]] = k)
        for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    return;
}

int main(){
	while(~scanf("%s%s",a,b)){
		int lenA=strlen(a);
		for(int i=0;i<=lenA;++i)
			s[i]=a[i];
		s[lenA]='$';
		int lenB=strlen(b);
		for(int i=0;i<=lenB;++i)s[lenA+i+1]=b[i];
		SA(s,sa,lenA+lenB+1,'z'+1);
		Height(s,sa,lenA+lenB);
		int res=0;
		for(int i=1;i<=lenA+lenB;++i){
			if(height[i]>res){
				int x=sa[i],y=sa[i-1];
				if((x<lenA&&y>lenA)||(x>lenA&&y<lenA))res=height[i];
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
