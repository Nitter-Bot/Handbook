queue<int> q;
q.push(0);
while(!q.empty()){
	int u = q.front();
	q.pop();
	for(int v:adj[u]){
		if (!vis[v]) {
			vis[v] = 1;
			q.push(v);
		}
	}
}
