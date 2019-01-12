T=int(input())
for _ in range(T):
	N=int(input())
	print("B" if N%7==2 or N%7==0 else "A")
