vector<bool> removed(n+1);
vi sub(n+1);

auto dfs = [&](auto &self,int u,int p)->void{
	sub[u] = 1;
	for(int v:adj[u]){
		if(v!=p && !removed[v]){
			self(self,v,u);
			sub[u] += sub[v];
		}
	}
};

auto centroid = [&](auto &self,int u,int p,int root)->int{
	for(int v:adj[u]){
		if(v!=p && !removed[v]){
			if(sub[v]*2 > sub[root])
				return self(self,v,u,root);
		}
	}
	return u;
};

auto info = [&](auto &self,int u,int p,int d,vi &aux)->void{
	d ^= a[u-1];
	aux.pb(d);
	for(int v:adj[u])
		if(v!=p && !removed[v])
			self(self,v,u,d,aux);
};

auto decompose = [&](auto &self,int u,int p)->void{
	dfs(dfs,u,p);
	int c = centroid(centroid,u,p,u);
	//get info
	removed[c] = 1;
	for(int v:adj[c]){
		if(v!=p && !removed[v])
			self(self,v,c);
	}
};
