vector<vector<pll>> adj(9*n+1);
vi pos(n);

auto dfs = [&](auto &self,int v,int tl,int tr)->void{
	if(tl == tr){
		pos[tl] = v;
		adj[v].pb({v+4*n,0});
		return;
	}
	adj[v].pb({v<<1,0});//par to child
	adj[v].pb({(v<<1)|1,0});

	adj[(v<<1)+4*n].pb({v+4*n,0});//child to par
	adj[((v<<1)|1)+4*n].pb({v+4*n,0});

	int tm = tl+(tr-tl)/2;
	self(self,v<<1,tl,tm);
	self(self,(v<<1)|1,tm+1,tr);
};

dfs(dfs,1,0,n-1);

auto range = [&](auto &self,int v,int tl,int tr,int l,int r,int op,int u,int w)->void{
	if(l>tr||r<tl)return;
	if(tl>=l && tr<=r){
		if(op)adj[pos[u]].pb({v,w});//u to range
		else adj[v+4*n].pb({pos[u],w});//range to u
		return;
	}
	int tm = tl+(tr-tl)/2;
	self(self,v<<1,tl,tm,l,r,op,u,w);
	self(self,(v<<1)|1,tm+1,tr,l,r,op,u,w);
};
