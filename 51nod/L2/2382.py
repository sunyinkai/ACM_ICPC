#tag: multiply
x=int(input())
ans=5**x
t=ans
digit=0
while t is not 0 :
    digit+=1
    t//=10
print("0.",end="")
while digit<x:
    print("0",end="")
    digit+=1
print(ans)
