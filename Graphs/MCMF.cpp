struct MCMF{
	struct edge{
		int u, v;
		ll cap, cost;
		int id;
		edge(int _u, int _v, ll _cap, ll _cost, int _id) {
			u = _u;
			v = _v;
			cap = _cap;
			cost = _cost;
			id = _id;
		}
	};

	int n, s, t, mxid;
	ll flow, cost;
	vector<vi> g;
	vector<edge> e;
	vll d, potential, flow_through;
	vi par;
	bool neg;

	MCMF(){}
	//0 indexed
	MCMF(int _n){
		n = _n + 10;
		g.assign(n, vector<int> ());
		neg = false;
		mxid = 0;
	}

	void add_edge(int u, int v, ll cap, ll cost, int id = -1, bool directed = true) {
		if(cost < 0) neg = true;
		g[u].push_back(e.size());
		e.push_back(edge(u, v, cap, cost, id));
		g[v].push_back(e.size());
		e.push_back(edge(v, u, 0, -cost, -1));
		mxid = max(mxid, id);
		if(!directed) add_edge(v, u, cap, cost, -1, true);
	}

	bool dijkstra(){
		par.assign(n, -1);
		d.assign(n, INF64);
		priority_queue <pll,vector<pll>,greater<pll>> q;
		d[s] = 0;
		q.push({0, s});

		while (!q.empty()){
			auto [nw,u] = q.top();
			q.pop();
			if(nw != d[u])continue;
			for (int i = 0; i < sz(g[u]); i++) {
				int id = g[u][i];
				int v = e[id].v;
				ll cap = e[id].cap;
				ll w = e[id].cost + potential[u] - potential[v];
				if (d[u]+w < d[v] && cap > 0) {
					d[v] = d[u] + w;
					par[v] = id;
					q.push({d[v], v});
				}
			}
		}

		for (int i = 0; i < n; i++){
			if (d[i] < INF64)
				d[i] += (potential[i] - potential[s]);
		}

		for (int i = 0; i < n; i++){
			if (d[i] < INF64) potential[i] = d[i];
		}
		return d[t] != INF64; // for max flow min cost
		// return d[t] <= 0; // for min cost flow
	}

	ll send_flow(int v, ll cur){
		if(par[v] == -1) return cur;
		int id = par[v];
		int u = e[id].u;
		ll w = e[id].cost;
		ll f = send_flow(u, min(cur, e[id].cap));
		cost += f * w;
		e[id].cap -= f;
		e[id ^ 1].cap += f;
		return f;
	}

	pll solve(int _s, int _t, ll goal = INF64) {
		s = _s;
		t = _t;
		flow = 0, cost = 0;
		potential.assign(n, 0);
		if(neg){
			d.assign(n, INF);
			d[s] = 0;
			bool relax = true;
			for (int i = 0; i < n && relax; i++) {
				relax = false;
				for (int u = 0; u < n; u++) {
					for (int k = 0; k < (int)g[u].size(); k++) {
						int id = g[u][k];
						int v = e[id].v;
						ll cap = e[id].cap, w = e[id].cost;
						if (d[v] > d[u] + w && cap > 0) {
							d[v] = d[u] + w;
							relax = true;
						}
					}
				}
			}
			for(int i = 0; i < n; i++) if(d[i] < INF) potential[i] = d[i];
		}
		while (flow < goal && dijkstra()) flow += send_flow(t, goal - flow);
		flow_through.assign(mxid + 10, 0);
		for (int u = 0; u < n; u++){
			for (auto v : g[u])
				if (e[v].id >= 0) flow_through[e[v].id] = e[v ^ 1].cap;
		}

		return make_pair(flow, cost);
	}
};
