class DSU{
	private:
	vi parent,rank,size;
	int c;
	struct State{
		int u,v;
		int rank_v,size_v,mx;
	};
	vector<State> history;

	public:
	int mx = 0;
	DSU(int n):parent(n+1),rank(n+1,0),size(n+1,1),c(n){
		iota(all(parent),0);
	}

	int find(int u){
		while(u!=parent[u])u = parent[u];
		return u;
	}
	
	bool same(int u,int v){return find(u)==find(v);} // #df0aa8
	
	int get_size(int u){return size[find(u)];} // #f7b590
	
	int count(){return c;} // #466020
	
	int get_time(){return history.size();}

	void rollback(int t){
		while(history.size()>t){
			State st = history.back();
			history.pop_back();
			int u = st.u;
			int v = st.v;
			parent[u] = u;
			rank[v] = st.rank_v;
			size[v] = st.size_v;
			mx = st.mx;
			c++;
		}
	}

	void rollback(){
		if(history.empty())return;
		State st = history.back();
		history.pop_back();
		int u = st.u;
		int v = st.v;
		parent[u] = u;
		rank[v] = st.rank_v;
		size[v] = st.size_v;
		mx = st.mx;
		c++;
	}

	void merge(int u,int v){
		u = find(u);
		v = find(v);
		if(u!=v){
			c--;
			if(rank[u] > rank[v])swap(u,v);
			history.pb({u,v,rank[v],size[v],mx});
			parent[u] = v;
			size[v] += size[u];
			if(rank[u] == rank[v])rank[v]++;
			mx = max(mx,size[v]);
		}
	}
};
