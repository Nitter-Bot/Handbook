const int MAX = 1e5+5,LG=18;
vector<vector<pii>> adj(MAX,vector<pii> ());
vi deep(MAX);
int par[MAX][LG+1];
int mn[MAX][LG+1];
int mx[MAX][LG+1];
 
void dfs(int u=1,int p=0,int costmn = INF,int costmx = -INF){
	par[u][0] = p;
	deep[u] = deep[p]+1;
 
	if(p!=0){
		mn[u][0]  = costmn;
		mx[u][0]  = costmx;
	}
	for(int i=1;i<=LG;i++){
		par[u][i]=par[par[u][i-1]][i-1];
		mn[u][i]=min(mn[u][i-1],mn[par[u][i-1]][i-1]);
		mx[u][i]=max(mx[u][i-1],mx[par[u][i-1]][i-1]);
	}
 
	for(auto [v,t]:adj[u]){
		if(v!=p){
			dfs(v,u,t,t);
		}
	}
}
 
pii minmax(int u,int v){
	pii ans = {INF,-INF};
	if(deep[u] < deep[v])swap(u,v);
	for(int k=LG;k>=0;k--)if(deep[par[u][k]] >= deep[v]){
		ans.F = min(ans.F,mn[u][k]);
		ans.S = max(ans.S,mx[u][k]);
		u = par[u][k];
	}
	if(u==v)return ans;
	for(int k=LG;k>=0;k--)if(par[u][k]!=par[v][k]){
		ans.F = min({ans.F,mn[u][k],mn[v][k]});
		ans.S = max({ans.S,mx[u][k],mx[v][k]});
		u=par[u][k],v=par[v][k];
	}
	ans.F = min({ans.F,mn[u][0],mn[v][0]});
	ans.S = max({ans.S,mx[u][0],mx[v][0]});
 
	return ans;
}
