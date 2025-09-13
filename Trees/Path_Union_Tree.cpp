pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
	if (x.first == 0)return y; //where {0,0} is a null path
	if (y.first == 0)return x;
	if (x.first == -1 || y.first == -1)   return { -1, -1};
	vector<int> can = {x.first, x.second, y.first, y.second};
	int a = can[0];
	for (int u : can)
		if (dep[u] > dep[a])
			a = u;
	int b = -1;
	for (int u : can)
		if (!isanc(a, u)) {
			if (b == -1)  b = u;
			if (dep[b] < dep[u])    b = u;
		}
	if (b == -1) {
		b = can[0];
		for (int u : can)
			if (dep[u] < dep[b])
				b = u;
		return {a, b};
	}
	int g = lca(a, b);
	for (int u : can) {
		if (u == a || u == b)continue;
		if (dep[u] < dep[g] || (!isanc(a, u) && !isanc(b, u)))return { -1, -1};
	}
	return {a, b};
}
