//T[x] tiempo entrada
auto virtualTree = [&](vi &v)->vi{
	sort(all(v),[&](int x,int y){
		return T[x] < T[y];
	});
	int aux = sz(v)-1;
	for(int i=0;i<aux;i++)
		v.pb(lca(v[i],v[i+1]));

	sort(all(v),[&](int x,int y){
		return T[x] < T[y];
	});
	v.erase(unique(all(v)),v.end());

	stack<int> st;
	st.push(v[0]);
	for(int i=1;i<sz(v);i++){
		while(!st.empty() && !isanc(v[i],st.top()))st.pop();
		tree[st.top()].push_back(v[i]);
		st.push(v[i]);
	}
	return v;
};
