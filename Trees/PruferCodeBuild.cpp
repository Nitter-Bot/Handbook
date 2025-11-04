auto dfs = [&](auto &self,int u){
    for (int v:adj[u]) {
        if (v != parent[u]) {
            parent[v] = u;
            dfs(v);
        }
    }
};

parent[n] = -1;
dfs(dfs,n);

int ptr = -1;
vi degree(n);
for(int i=1;i<=n;i++) {
        degree[i] = sz(adj[i]);
        if(degree[i]==1 && ptr==-1)
		ptr = i;
}

vi code(n - 2);
int leaf = ptr;
for(int i=0;i<n-2;i++){
	int next = parent[leaf];
	code[i] = next;
	if (--degree[next]==1 && next<ptr) {
		leaf = next;
	}else{
		ptr++;
		while (degree[ptr] != 1)
			ptr++;
		leaf = ptr;
	}
}
