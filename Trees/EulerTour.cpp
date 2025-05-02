int timer = 0;
vi start,final;
vector<vi> adj;
void dfs(int u = 0,int prev = -1){
	start[u]=timer++;
	for(int v:adj[u]){
		if(v!=prev)dfs(v,u);
	}
	final[u] = timer;
}
// [start,final)
