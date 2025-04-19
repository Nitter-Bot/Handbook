vector<vector<pii>> adj;
vector<bool> vis;
 
int bfs(int n,vll &d,int v = 0){
	vis.assign(n,0);
	d.assign(n,0);
	d[v] = 0;
	queue<int> q;
	q.push(v);
	pll last = {v,0};
	vis[v] = 1;
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto [w,c]:adj[u]){
			if(vis[w])continue;
			d[w] = d[u]+c;
			q.push(w);
			vis[w] = 1;
			if(d[w]>last.S)last = {w,d[w]};
		}
	}
	return int(last.F);
}
 
void solve(){
	int n;cin >> n;
	adj.assign(n,vector<pii> ());
	for(int i=1;i<n;i++){
		int a,b;ll c;
		cin >> a >> b >> c;
		adj[--a].pb({--b,c});
		adj[b].pb({a,c});
	}
	vll dx(n),dy(n);
	int a =bfs(n,dx);
	int b =bfs(n,dy,a);
	bfs(n,dx,b);
 
	for(int i=0;i<n;i++){
		cout << max(dx[i],dy[i]) << " \n"[i==(n-1)];
	}
 
}
