//1-indexed

auto centers = [&](vector<vi> &adj)->vi{
	//Diameters of a tree
	vll du(n+1),dv(n+1);
	int v =bfs(du,1,adj);
	int u =bfs(dv,v,adj);
	bfs(du,u,adj);
	vi ans;
	for(int i=1;i<=n;i++)
		if(du[i]+dv[i]==du[v] && du[i]>=du[v]/2 && dv[i]>=du[v]/2)
			ans.pb(i);
	return ans;
};

//in main

vi a = centers(tree1);
vi b = centers(tree2);

for(auto x:a)
	for(auto y:b)
		//checar isomorfismos si estan rooteados 
		//en x y y
