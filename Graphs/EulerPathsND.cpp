struct EulerSolver{
private:
	vector<vector<pii>> adj;
	int n,edges;
	vi ans,edge_ans;
	vi deg;
	int root;
	vi done;
	vector<bool> vis;
	
	void dfs(int u){
		while(done[u] < sz(adj[u])){
			auto [v,id] = adj[u][done[u]++];
			if(vis[id])continue;
			vis[id]=1;
			dfs(v);
			edge_ans.pb(id);
		}
		ans.pb(u);
	}
public:
	EulerSolver(vector<vector<pii>> &a,int t):adj(a),n(t){
		edges = 0;
		done.assign(n,0);
		deg.assign(n,0);
		root = -1;
		for(int u=0;u<n;u++)
			for(auto v:adj[u]){
				edges++;
				deg[v.F]++;
				deg[u]++;
			}
		vis.assign(edges/2,0);
	}

	bool possible(){
		int odd = 0;
		for(int i=0;i<n;i++)
			if((deg[i]/2)&1){
				odd++;
				root = i;
			}
		
		
		if(odd>2)return 0;

		if(root == -1)
			for(int i=0;i<n;i++)
				if(deg[i]){root = i;break;}

		if(root == -1)return 1;
		dfs(root);

		if(sz(ans) != edges/2+1)return 0;
		reverse(all(ans));
		reverse(all(edge_ans));
		return 1;
	}

	int size(){
		return ans.size();
	}

	int operator()(int i,bool x){
		if(x)return ans[i];
		else return edge_ans[i];
	}
};

