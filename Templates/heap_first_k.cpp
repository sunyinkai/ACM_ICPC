#include<cstdio>
#include<algorithm>
using namespace std;

class Solution {
public:
    void build(vector<int>&a,int len){
        //自底向上建堆
        for(int i=len/2;i>=0;--i){
            int t=i;
            while(t<len){
                int to=-1;
                int l=t*2+1;
                if(l<len&&a[l]<a[t]){
                    to=l;
                }
                int r=t*2+2;
                if(r<len&&a[r]<a[t]){
                    if(to==-1||a[r]<a[to])to=r;
                }
                if(to==-1)break;
                swap(a[t],a[to]);
                t=to;
            }
        }
    }

    int pop(vector<int>&a,int len){
        //将最小的设为INF,然后往下拉,shift_down
        //下拉过程，找到最小子树最小的，交换位置即可
        const int INF=2e9+7;
        int val=a[0];
        a[0]=INF;
        int t=0;
        while(t<len){
            int to=-1;
            int l=t*2+1;
            if(l<len&&a[l]<a[t]){
                to=l;
            }
            int r=t*2+2;
            if(r<len&&a[r]<a[t]){
                if(to==-1||a[r]<a[to])to=r;
            }
            if(to==-1)break;
            swap(a[t],a[to]);
            t=to;
        }
        return val;
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        build(input,len);
        vector<int>ans;
        while(k--){
 //           for(int i=0;i<len;++i)
 //              printf("%d ",input[i]);
 //           printf("\n--------------\n");
            int val=pop(input,len);
           printf("val:%d\n",val);
            ans.push_back(val);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>G{2,4,5,1,6,2,7,3,8};
    s.GetLeastNumbers_Solution(G,8);
    return 0;
}
