void dfs(int u){
	vis[u] = 1;
	for(auto v:adj[u]){
		if(!vis[v])dfs(v);
	}
}
