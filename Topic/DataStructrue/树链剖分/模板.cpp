//剖分后,重链上的编号连续
//子树上的编号连续,dfs序性质
//x到y上的所有节点值加上x
//给x的子树内所有节点的值加上x
void dfs_1(int u,int pre,int d){
	dep[u]=d;
	size[u]=1;
	par[u]=pre
	son[u]=-1;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		dfs_1(v,u,d+1);
		size[u]+=size[v];
		if(son[u]==-1||size[v]>size[son[u]]){//得到重儿子
			son[u]=v;
		}
	}
}
//以根节点为起点往下拉重链,而不在重链上的点,以该节点为起点再拉链
void dfs_2(int u,int sp){
	top[u]=sp;
	p[u]=++time;
	fp[p[u]]=u;
	if(son[u]==-1)return;
	dfs(son[u],sp);
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==son[u]||v==par[u])continue;
		dfs_2(v,v);
	}
}
int find(int u,int v){//询问最大值
	int tmp=0;
	while(top[u]!=top[v]){//两个点不在一条重链上
		if(dep[top[u]]<dep[top[v]]){
			swap(u,v);//把u改为深度更深的那个点
		}
		tmp=max(tmp,query(1,p[top[u]],p[u]));
		u=par[top[u]];
	}
	//直到两个点处于同一个链上
	if(u==v)return tmp;
	if(dep[u]>dep[v])swap(u,v);
	return max(tmp,query(1,p[son[u]],p[v]));
}
