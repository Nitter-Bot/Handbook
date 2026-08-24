const int LG = 18;

vi deep(n+1);
vector<vi> par(n+1,vi(LG+1));

auto dfs = [&](auto &self,int u,int p)->void{
	par[u][0] = p;
	deep[u] = deep[p]+1;//cost[u] += cost[p]
	for(int i=1;i<=LG;i++)par[u][i]=par[par[u][i-1]][i-1];
	for(int v:adj[u])
		if(v!=p)
			self(self,v,u);
};

auto lca = [&](int u,int v)->int{
	if(deep[u] < deep[v])swap(u,v);
	for(int k=LG;k>=0;k--)
		if(deep[par[u][k]] >= deep[v])
			u = par[u][k];
	if(u==v)return u;
	for(int k=LG;k>=0;k--)
		if(par[u][k]!=par[v][k])
			u=par[u][k],v=par[v][k];
	return par[u][0];
};

auto dist = [&](int u,int v)->int{
	int lc = lca(u,v);
	return deep[u]+deep[v]-(deep[lc]<<1);
};

auto kth = [&](int u, int k)->int{
	assert(k>=0);
	for(int i=0;i<=LG;i++)
		if(k&(1<<i))u = par[u][i];
	return u;
};

auto isanc = [&](int u,int g)->bool{
	int k = deep[u]-deep[g];
	return k >= 0 && kth(u, k) == g;
};
