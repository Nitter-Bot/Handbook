vector<vi> color;
bool ok = 1;
queue<int> q;
for(int i=0;i<n;i++){
	if(a[i]!=0)continue;
	q.push(i);
	color[i] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for(int u:adj[v]){
			if(a[u]==0){
				a[u] = a[v]^3;
				q.push(u);
			}else{
				valid &= a[u]!=a[v];
			}
		}
	}
}
