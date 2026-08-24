auto dfs = [](auto &self,int u,int p,vector<vi> &adj)->pair<ll,ll>{
	vector<pair<ll,ll>> shash;
	for(int v:adj[u]){
		if(v==p)continue;
		shash.pb(self(self,v,u,adj));
	}
	sort(all(shash));

	ll p1 = P1,p2 = P2;
	pair<ll,ll> hash = {42,42};
	for(int i=0;i<sz(shash);i++,(p1*=p1)%=MOD1,(p2*=p2)%=MOD2){
		(hash.F += shash[i].F*shash[i].F%MOD1+shash[i].F*p1%MOD1+42)%MOD1;
		(hash.S += shash[i].S*shash[i].S%MOD2+shash[i].S*p2%MOD2+42)%MOD2;
	}
	return hash;
};
