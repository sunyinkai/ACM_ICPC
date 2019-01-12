def gcd(A,B):
	if B==0:
		return A
	else:
		return gcd(B,A%B)

if __name__=='__main__':
	A,B=map(int,input().strip().split(' '))
	print(gcd(A,B))
