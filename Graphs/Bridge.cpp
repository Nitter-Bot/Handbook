
vector<pii> bridge;
vi disc(MAX),low(MAX);
vector<vi> adj(MAX);
int Time = 0;

void dfs(int u,int p){
	disc[u] = low[u] = ++Time;
	for(int v:adj[u]){
		if(v==p)continue;
		if(!disc[v]){
			dfs(v,u);
			// <= for articulation points
			if(disc[u]<low[v])bridge.emplace_back(u,v);
			low[u] = min(low[u],low[v]);
		}else{
			low[u] = min(low[u],disc[v]);
		}

	}
}

