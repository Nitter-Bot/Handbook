struct EulerSolver{
private:
	vector<vector<pii>> adj;
	int n,edges;
	vi in,out;
	vi ans,edge_ans;
	int root;
	vi done;
	void dfs(int u){
		while(done[u] < sz(adj[u])){
			auto [v,id] = adj[u][done[u]++];
			dfs(v);
			edge_ans.pb(id);
		}
		ans.pb(u);
	}
public:
	EulerSolver(vector<vector<pii>> &a,int t):adj(a){
		n = t;
		edges = 0;
		in.assign(n,0);
		out.assign(n,0);
		done.assign(n,0);
		root = -1;
		for(int u=0;u<n;u++)
			for(auto v:adj[u]){
				edges++;
				in[v.F]++;
				out[u]++;
			}

	}

	bool possible(){
		int cnt1 =0,cnt2 =0;
		bool ok = 1;
		for(int i=0;i<n;i++){
			if (in[i] - out[i] == 1) cnt1++;
			if (out[i] - in[i] == 1) cnt2++, root = i;
			if (abs(in[i] - out[i]) > 1) ok = 0;
		}
		if(cnt1 > 1 || cnt2 > 1)ok = 0;
		if(!ok)return 0;

		if(root == -1)
			for(int i=0;i<n;i++)
				if(out[i])root = i;

		if(root == -1)return 1;
		dfs(root);

		if(sz(ans) != edges+1)return 0;
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
