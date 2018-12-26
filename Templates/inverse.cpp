long long inv(long long a,long long p){//p为质数,a<p
	return a==1?1:(p-p/a)*inv(p%a,p)%p;
}
