// Hash: 60e0d3
class DSU{
	private:
	vi parent,rank,size;
	int c;
	public:
	int mx = 0; // #9e8891
	DSU(int n):parent(n+1),rank(n+1,0),size(n+1,1),c(n){
		iota(all(parent),0);
	} // #9dff24
	
	int find(int u){return parent[u] == u?u:parent[u] = find(parent[u]) ;} // #a9e220
	
	bool same(int u,int v){return find(u)==find(v);} // #df0aa8
	
	int get_size(int u){return size[find(u)];} // #f7b590
	
	int count(){return c;} // #466020
	
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
	} // #ee7199
};
