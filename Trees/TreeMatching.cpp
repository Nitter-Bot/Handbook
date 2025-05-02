vector<vll> dp(2,vll(MAX));

void dfs(ll u = 0, ll p=-1){
	dp[0][u] = 0;
	dp[1][u] = -INF;

	for(ll v:adj[u]){
		if(v == p)continue;
		dfs(v,u);

		dp[0][u]+=max(dp[1][v],dp[0][v]);

		ll opt = min(dp[0][v]-dp[1][v],0ll);

		dp[1][u] = max(dp[1][u],opt);
	}

	dp[1][u] += dp[0][u];
	dp[1][u]++;
}
