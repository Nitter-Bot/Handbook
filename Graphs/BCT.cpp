vector<vi> adj(n+1),bcc(n+1);
vi disc(n+1),low(n+1),who(n+1);
stack<int> st;
int Time = 0,sz = 0;

auto dfs = [&](auto &self,int u,int p)->void{
	disc[u] = low[u] = ++Time;
	st.push(u);
	for(int v:adj[u]){
		if(!disc[v]){
			self(self,v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] >= disc[u]){
				sz++;
				int x;
				do{
					x = st.top();
					st.pop();
					bcc[x].pb(sz);
				}while(x^v);
				bcc[u].pb(sz);
			}
		}else if(v!=p)low[u] = min(low[u],disc[v]);
	}
};

for(int i=1;i<=n;i++)
	if(!disc[i])dfs(dfs,i,0);

int c = sz+n+2;
vector<vi> tree(c);
vector<bool> art(c,0);
for(int i=1;i<=n;i++){
	if(sz(bcc[i])>1){
		who[i] = ++sz;
		art[who[i]] = 1;
		for(int v:bcc[i]){
			tree[who[i]].pb(v);
			tree[v].pb(who[i]);
		}
	}else if(sz(bcc[i])==1)who[i] = bcc[i][0];
}
