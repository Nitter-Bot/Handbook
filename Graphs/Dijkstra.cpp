vll dist(n,INF64);
vector<bool> vis(n,0);
priority_queue<pll,vector<pll>,greater<pll>> pq;
pq.emplace(0,0);
dist[0] = 0;
vll cnt(n,0);//number of shortest paths
while(!pq.empty()){
	auto [d1,u] = pq.top();
	pq.pop();
	if(vis[u])continue;
	vis[u] = 1;
	for(auto [v,c]:adj[u]){
		if(dist[u]+c < dist[v]){
			dist[v] = dist[u]+c;
			pq.emplace(dist[v],v);
			cnt[v] = cnt[u];
		}else if(dist[u]+c == dist[v])(cnt[v]+=cnt[u])%=MOD
	}
}
