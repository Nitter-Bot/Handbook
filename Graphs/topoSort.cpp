vi ts;
queue<int> q;
for (int i = 1; i < n+1; i++) 
	if(!in[i])q.push(i);

while (!q.empty()) {
	int u=q.front();
	q.pop();
	ts.pb(u);
	for (int v : adj[u]) {
		in[v]--;
		if(!in[v])q.push(i);
	}
}

if(sz(ts)!=n)cout <<"IMPOSSIBLE";
