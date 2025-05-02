typedef array<ll,3> T;
priority_queue<T ,vector<T>,greater<T>> pq;
pq.push({0,0,state[0]});
dist[0][state[0]]= 0;
while(!pq.empty()){
	auto [d,u,s] = pq.top();
	pq.pop();
	if(vis[u][s])continue;
	vis[u][s] = 1;
	for(auto [v,w]:adj[u]){
		ll c  = min(s,slow[v]);
		//Nuevo estad cuando llegue a V
		if(dist[u][s]+w*s<dist[v][c]){
			dist[v][c] = dist[u][s]+w*s;
			pq.push({dist[v][c],v,c});
		}
	}
}
