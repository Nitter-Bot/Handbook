vector<AC> a(19);// log aho corasick
vector<vector<string>> ws;
int cnt = 0;//number of strings insert

auto insert = [&](string &s){
	int pos = 0;
	for(int i=0;i<19;i++)
		if(ws[i].empty()){
			pos = i;
			break;
		}
	
	ws[pos].pb(s);
	for(int i=0;i<pos;i++){
		for(auto &str:ws[i])
			ws[pos].pb(move(str));
		ws[i].clear();
		w[i] = AC();
	}

	w[pos] = AC();
	
	for(int i=0;i<sz(ws[pos]);i++)w[pos].insert(ws[pos][i],i+1);

	w[pos].build();

};

auto query = [&](string &s)->ll{
	ll ans = 0;
	for(int i=0;i<19;i++)
		if(cnt>>i&1)
			ans += a[i].count(s);
};
