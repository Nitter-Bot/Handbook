struct Edge{
	int u,v,w;
	bool operator < (Edge b){return w<b.w;}
};

//inside main

vector<Edge> edges;
sort(all(edges));

DSU dsu(vertices);

for(int i=0;i<E;i++){
	Edge front = edges[i];
	if(!dsu.same(front.u,front.v)){
		cost+= front.w;
		dsu.merge(front.u,front.v);
	}
}
