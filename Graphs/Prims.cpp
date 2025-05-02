vector<bool> vis(n);
priority_queue<pii, vector<pii>, greater<pii>> q;

auto process = [&](int u){
	vis[u] = 1;
	for(int i=0;i<sz(adj[u]);i++){
		pii v = adj[u][i];
		swap(v.S,v.F);
		q.push(v);
	}
}
process(0);

while(!q.empty()){
	auto [w,u] = q.top();q.pop();
	if(!vis[u]){cost += w;process(u);}
}
