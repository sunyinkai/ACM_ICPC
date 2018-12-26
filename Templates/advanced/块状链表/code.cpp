#include<cstdio>
#include<vector>
#include<list>
using namespace std;
int sz;//块大小,一般为sqrt(n) 
struct BLOCK{vector<int>data;BLOCK(){}};
list<BLOCK>List;
typedef list<BLOCK>::iterator L_ITER;
typedef vector<int>::iterator V_ITER;
inline L_ITER next(L_ITER x){x++; return x;}//返回x的下一个块

//定位
inline L_ITER Find_Pos(const int &p)//返回整个块链中,下标p所在的块,下标默认从1开始 
{
    int cnt=0;
    for(L_ITER it=List.begin();it!=List.end();it++)
      {
          cnt+=(*it).data.size();
          if(cnt>=p) return it;
      }
}
//维护链表形态，大小在 [sqrt(n)/2,sqrt(n)*2]间
 void Merge(L_ITER a,L_ITER b)//将b合并给a 
{
     (*a).data.insert((*a).data.end(),(*b).data.begin(),(*b).data.end());
     List.erase(b);
}

void MaintainList()//维护块链的形态,保证每块的元素数恰当 
{
    L_ITER curB=List.begin();//将指针置于链表表头 
    while(curB!=List.end())
      {
          L_ITER nextB=next(curB);
          while(nextB!=List.end()&&(*curB).data.size()+(*nextB).data.size()<=sz)
            {
                Merge(curB,nextB);
                nextB=next(curB);
            }
          curB++;
      }
}
//分裂
void Split(L_ITER curB,int p)//在curB的p前分裂该块 
{
    if(p==(*curB).data.size()) return;//分裂的位置在末尾，不需要分裂 
    L_ITER newB=List.insert(next(curB),BLOCK());//在curB的后面插入一个新的块
    (*newB).data.assign((*curB).data.begin()+p,(*curB).data.end());//将原来块的后半部分数据复制给新块 
    (*curB).data.erase((*curB).data.begin()+p,(*curB).data.end());//将原来块中的后半部分元素删除 
}
//插入
void Insert(const int &p,const int &x,const int &v)//在p处插入x个数,待插入的权值均为v
{
    L_ITER curB=Find_Pos(p);
    Split(curB,p);
    int cnt=0;
    while(cnt+sz<=x)
      {
          L_ITER newB=List.insert(next(curB),BLOCK());
          (*newB).data.assign(sz,v);//设置新块的数据
          curB=newB;
          cnt+=sz;
      }
    if(x-cnt!=0)
      {
          L_ITER newB=List.insert(next(curB),BLOCK());
          (*newB).data.assign(sz,v);//设置新块的数据
      }
    MaintainList();
}
//删除
void Erase(const int &p,int x)//删除块链中从p位置开始的x个数
{
    L_ITER curB=Find_Pos(p);
    Split(curB,p); curB++;
    L_ITER nextB=curB;
    while(nextB!=List.end()&&x>(*nextB).data.size())
      {
          x-=(*nextB).data.size();
          nextB++;
      }
    Split(nextB,x);
    List.erase(curB,next(nextB));//将[curB,nextB]全部删除 
    MaintainList();
}
int main(){

	return 0;
}
