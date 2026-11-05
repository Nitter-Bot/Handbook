vi size(n+1,0),tin(n+1),tout(n+1),val;
int T = 0;
auto dfs = [&](auto &self,int u,int p)->void{
	tin[u] = T++;
	size[u] = 1;
	val.pb(u);
	for(int v:adj[u])if(v!=p)
		self(self,v,u),size[u]+=size[v];
	tout[u] = T;
};

dfs(dfs,1,0);

auto dfs2 = [&](auto &self,int u,int p,bool ok)->void{
	int mx = -1,big = -1;
	for(int v:adj[u])
		if(v!=p && size[v] > mx)
			mx = size[v],big = v;

	for(int v:adj[u])
		if(v!=p && v!=big)self(self,v,u,0);

	if(big!=-1)
		self(self,big,u,1);

	
	auto add = [&](int x){
		//function to add things to the global array
	};

	for(int v:adj[u])
		if(v!=p && v!=big)
			for(int p = tin[v];p<tout[v];p++)
				add(val[p]);//node in pos p of the euler tour
	
	add(u);

	if(ok == 0)
		for(int p = tin[u];p<tout[u];p++)
			//remove elements
};

dfs2(dfs2,1,0,1);
