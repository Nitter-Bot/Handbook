const int MAX = 1e5+5,LG=18;
vi deep(MAX);//Si tiene peso vi cost(MAX)
int par[MAX][LG+1];

void dfs(int u = 1,int p=0){// U = raiz del arbol
	par[u][0] = p;
	deep[u] = deep[p]+1;//cost[u] += cost[p]
	for(int i=1;i<=LG;i++)par[u][i]=par[par[u][i-1]][i-1];
	for(int v:adj[u]){
		if(v!=p){
			dfs(v,u);
		}
	}
}

int lca(int u,int v){
	if(deep[u] < deep[v])swap(u,v);
	for(int k=LG;k>=0;k--)
		if(deep[par[u][k]] >= deep[v])
			u = par[u][k];
	if(u==v)return u;
	for(int k=LG;k>=0;k--)
		if(par[u][k]!=par[v][k])
			u=par[u][k],v=par[v][k];
	return par[u][0];
}

int dist(int u,int v){
	int lc = lca(u,v);
	return deep[u]+deep[v]-(deep[lc]<<1);
}

int kth(int u,int k){
	assert(k>=0);
	for(int i=0;i<=LG;i++)
		if(k&(1<<i))u = par[u][i];
	return u;
}
