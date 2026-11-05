int m = 2*n+5,id = n+1;
vector<vi> adj(m);
vi val(m,0),par(m);
iota(all(par),0);

auto find = [&](auto &self,int u)->int{
	return par[u]==u?u:par[u] = self(self,par[u]);
};

auto merge = [&](int u,int v,int w)->void{
	u = find(find,u);
	v = find(find,v);
	if(u!=v){
		par[u] = par[v] = par[id] = id;
		adj[id] = {{u,w},{v,w}};
		val[id] = w;   // node weight (what you usually want)
		// HOOK: extra data, e.g. sz[id] = sz[u]+sz[v];
		id++;
	}
};

sort(all(edges)) //rall(e) for maximum tree 
for(auto [w,u,v]:e) merge(u,v,w);
int root = id-1;
