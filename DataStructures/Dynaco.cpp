struct Dynaco{
	int n;
	vector<vector<pii>> st;
	DSU dsu;//with rollbacks

	Dynaco(int T,int v):n(T),dsu(v){st.resize(4*n+1);}

	void add(int v, int tl, int tr, int l, int r, pii e){
		if(l>r)return;

		if(l==tl&&r==tr){
			st[v].push_back(e);
			return;
		}
		int tm = tl+(tr-tl)/2;
		add(v<<1,tl,tm,l,min(r,tm),e);
		add((v<<1)+1,tm+1,tr,max(l,tm+1),r,e);
	}


	void dfs(int v, int tl, int tr, vi& ans){
		int merges = 0;

		for(auto [x,y]:st[v])
			if(dsu.merge(x,y))merges++;

		if(tl==tr){
			ans[tl] += dsu.count();
		}else{
			int tm = tl+(tr-tl)/2;
			dfs(v<<1,tl,tm,ans);
			dfs((v<<1)+1,tm+1,tr,ans);
		}

		while(merges--)dsu.rollback();
	}
};
