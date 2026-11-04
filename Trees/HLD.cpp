struct HLD{
	int n;
	vector<vi> adj;
	vi par,depth,root,in,out;
	Segment_Tree tree;
	int T;

	int dfs_sz(int u,int p){
		int sz = 1, mx = 0;
		for(int &v:adj[u]){
			if(v==p)continue;
			par[v] = u;
			depth[v] = depth[u]+1;
			int sub = dfs_sz(v,u);
			sz += sub;
			if(sub>mx){
				mx = sub;
				swap(v,adj[u][0]);
			}
		}
		return sz;
	}

	void dfs_hld(int u,int p){
		in[u] = T++;
		for(auto v:adj[u]){
			if(v==p)continue;
			root[v] = (v==adj[u][0]?root[u]:v);
			dfs_hld(v,u);
		}
		out[u] = T;
	}

	template <class BinaryOperation>
	void processPath(int u,int v,BinaryOperation op){
		for(;root[u]!=root[v];v=par[root[v]]){
			if(depth[root[u]]>depth[root[v]])swap(u,v);
				op(in[root[v]],in[v]+1);
		}
		if(depth[u]>depth[v])swap(u,v);
		op(in[u],in[v]+1);
	}

	HLD(vector<vi> &tree_adj){
		this->n = sz(tree_adj);
		adj = tree_adj;
		par.assign(n,-1);
		depth.assign(n,0);
		root.assign(n,0);
		in.assign(n,0);
		out.assign(n,0);
		T = 0;

		dfs_sz(1,0);
		root[1] = 1;
		dfs_hld(1,0);

		tree = Segment_Tree(n);
	}

	void update(int u,int val){
		tree.update(in[u],val);
	}
	
	int query(int u){
		return tree.query(in[u]);
	}

	void updatePath(int u,int v,int val){// l,r-1
		processPath(u,v,[this,&val](int l,int r){
			tree.update(l,r-1);
		});
	}
	
	Node queryPath(int u, int v){
		Node res = {0};
		processPath(u, v, [&](int l, int r){
			tree.query(l,r-1);
		});
		return res;
	}


	void updateSub(int u,int val){
		tree.update_set(1,0,n-1,in[u],out[u]-1,val);
	}
	Node querySub(int u){
		return tree.query(in[u],out[u]-1);
	}
};
