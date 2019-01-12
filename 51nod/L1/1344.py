N=int(input())
ans=0
val=0
while N:
	x=int(input())
	ans+=x
	val=min(val,ans)
	N=N-1
print(-val)
