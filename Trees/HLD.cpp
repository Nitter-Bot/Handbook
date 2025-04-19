class HLD{
private:
	int n;
	vector<vi> adj;
	vi parent;
	vi heavy;
	vi depth;
	vi root;
	vi treePos;
	Segment_Tree tree;

	int dfs(int u =0){
		int size = 1, mx_sub = 0;
		for(auto v:adj[u])
			if(v!=parent[u]){
				parent[v] = u;
				depth[v] = depth[u]+1;
				int sub = dfs(v);
				if(sub > mx_sub){
					heavy[u] = v;
					mx_sub = sub;
				}
				size += sub;
			}
		return size;
	}
	
	template <class BinaryOperation>
	void processPath(int u, int v, BinaryOperation op) {
		for (; root[u] != root[v]; v = parent[root[v]]) {
			if (depth[root[u]] > depth[root[v]]) swap(u, v);
			op(treePos[root[v]], treePos[v] + 1);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(treePos[u], treePos[v] + 1);
	}

	void init(vi &a){
		for(int i=0,crt=0;i<n;++i){
			if(parent[i] == -1 || heavy[parent[i]]!=i){
				for(int j = i;j!=-1;j = heavy[j]){
					root[j] = i;
					treePos[j] = crt++;
				}
			}
		}
		tree = Segment_Tree(n);
		for(int i=0;i<n;i++){
			tree.update(treePos[i],a[i]);
		}
	}

public:

	HLD(int n,vector<vi> &vale,vi &a):n(n),adj(vale){
		parent.assign(n,0);
		heavy.assign(n,-1);
		depth.assign(n,0);
		root.resize(n);
		treePos.assign(n,0);
		parent[0] = -1;
		dfs();
		init(a);
	}

	void update(int u,int &val){
		tree.update(treePos[u],val);
	}

	void updatePath(int u, int v, int value) {
		processPath(u, v, [this, &value](int l, int r) {
			tree.update_range(l, r, value); 
		});
	}

	int query(int u,int v){
		int ans = 0;
		processPath(u,v,[this,&ans](int l,int r){
			ans = max(ans,tree.query(l,r));
		});
		return ans;
	}
};
