int SPFA( int start){
	queue<int>Q;
	for(int i = 1 ; i <= n ; i++ )
		dis[i] = INF;
	dis[start] = 0;
	++cont[start];
	memset(vis,false,sizeof(vis));
	Q.push(start);
	while(!Q.empty()){//直到队列为空
		int u = Q.front();
		Q.pop();
		vis[u] = false;
		for(int i = Edgehead[u] ; i!=-1 ; i = Edge[i].next){//注意
			int v = Edge[i].v;
			int w = Edge[i].w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u]+w;
				if( !vis[v] ){//防止出现环，也就是进队列重复了  
					Q.push(v);
					vis[v] = true;
				}
			//	if(++cont[v] > n)//有负环
			//		return -1;
			}
		}
	}
	return dis[n];
}
