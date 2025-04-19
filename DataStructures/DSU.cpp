class DSU{
	private:
	vi parent,rank,size;
	int c;
	public:
	int mx = 0;
	DSU(int n):parent(n+1),rank(n+1,0),size(n+1,1),c(n){
		iota(all(parent),0);
	}
	
	int find(int u){return parent[u] == u?u:parent[u] = find(parent[u]) ;}
	
	bool same(int u,int v){return find(u)==find(v);}
	
	int get_size(int u){return size[find(u)];}
	
	int count(){return c;}
	
	void merge(int u,int v){
		u = find(u);
		v = find(v);
		if(u!=v){
			c--;
			if(rank[u] > rank[v])swap(u,v);
			parent[u] = v;
			size[v] += size[u];
			if(rank[u] == rank[v])rank[v]++;
			mx = max(mx,size[v]);
		}
	}
};
