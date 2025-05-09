struct flowEdge{
int u,v;
ll cap,flow = 0; 
flowEdge(int u, int v, ll cap) : u(u), v(v), cap(cap) {};
};

struct Dinic{
vector<flowEdge> edges; 
vector<vi> adj; 
int n,s,t; 
int id = 0;
vi level, next; 

queue<int> q;

Dinic(int n, int s, int t) : n(n), s(s), t(t) {
	adj.resize(n);
	level.resize(n);
	next.resize(n);
	fill(all(level),-1); 
	level[s] = 0; 
	q.push(s);
}

void add(int u, int v, ll cap){
	edges.emplace_back(u,v,cap);
	edges.emplace_back(v,u,0);
	adj[u].pb(id++); 
	adj[v].pb(id++); 
}

bool bfs(){
	while (!q.empty()){
		int curr = q.front();
		q.pop();
		for (auto e : adj[curr]){
			if (edges[e].cap - edges[e].flow  < 1) continue; 
			if (level[edges[e].v] != -1) continue; 
			level[edges[e].v] = level[edges[e].u] + 1; 
			q.push(edges[e].v);
		}
	}
	return level[t] != -1; 
}

ll dfs(int u, ll flow){
	if (flow == 0) return 0;
	if (u == t) return flow;
	for (auto& cid = next[u]; cid < adj[u].size(); cid++){ 
	    int e = adj[u][cid]; 
	    int v = edges[e].v; 
 
	    if (level[edges[e].u] + 1 != level[v] || edges[e].cap - edges[e].flow < 1) continue;
	    ll f = dfs(v,min(flow,edges[e].cap - edges[e].flow)); 
	    if (f == 0) continue; 
	    edges[e].flow += f; 
	    edges[e ^ 1].flow -= f;
	    return f;
	}
	return 0;
}

ll maxFlow(){
	ll flow = 0;
	while (bfs()){
	    fill(all(next),0);
	    for (ll f = dfs(s,INF64); f != 0ll; f = dfs(s,INF64)) flow += f;
	    fill(all(level),-1); 
	    level[s] = 0;
	    q.push(s);
	}
	return flow;
    }


vector<pii> minCut(){
	vector<pii> ans;
	fill(all(level),-1);
	level[s] = 0;
	q.push(s);
	while (!q.empty()){
		int curr = q.front();
		q.pop();
		for (int id = 0; id < adj[curr].size(); id++){
			int e = adj[curr][id];
			if (level[edges[e].v] == -1 && edges[e].cap - edges[e].flow > 0){
				q.push(edges[e].v);
				level[edges[e].v] = level[edges[e].u] + 1; 
			}
		}
	}

	for (int i = 0; i < level.size(); i++){
		if (level[i] != - 1){
			for (int id = 0; id < adj[i].size(); id++){
			int e = adj[i][id];
			if (level[edges[e].v] == -1 && edges[e].cap - edges[e].flow == 0)
				ans.emplace_back(edges[e].u,edges[e].v);
			}
		}
	}
	return ans;
}

vector<pii> MaximumMatching(){
	vector<pii> ans;
	fill(all(level),-1);
	level[s] = 0;
	q.push(s);
	while (!q.empty()){
		int curr = q.front();
		q.pop();
		for (int id = 0; id < adj[curr].size(); id++){
		int e = adj[curr][id];
		if (level[edges[e].v] == -1 && edges[e].cap - edges[e].flow == 0 && edges[e].flow != 0ll){
				q.push(edges[e].v);
				level[edges[e].v] = level[edges[e].u] + 1;
			}
		}
	}
	for (int i = 0; i < level.size(); i++){
		if (level[i] != - 1)
			for (int id = 0; id < adj[i].size(); id++){
				int e = adj[i][id];
				if (edges[e].u != s && edges[e].v != t && edges[e].cap - edges[e].flow == 0 && edges[e].flow != 0ll)
					ans.emplace_back(edges[e].u,edges[e].v);
			}
	}
	return ans;
}

};
