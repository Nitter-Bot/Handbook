//Bridges alredy found
vi who(n+1,-1);
int c = 1;

auto dfs2 = [&](auto &self,int u)->void{
	who[u] = c;
	for(auto [v,i]:adj[u]){
		if(who[v]!=-1||bridge[i])continue;
		self(self,v);
	}
};


for(int i=1;i<=n;i++){
	if(who[i]==-1)dfs2(dfs2,i),c++;
}

vector<vi> tree(c);

for(int i=0;i<m;i++){
	if(bridge[i]){
		tree[who[edges[i].u]].pb(who[edges[i].v]);
		tree[who[edges[i].v]].pb(who[edges[i].u]);
	}
}
