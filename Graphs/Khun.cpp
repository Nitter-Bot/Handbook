// adj[u] = right-side neighbors of left vertex u
// stops once `need` matches are found
// returns {match, i} where i is the left vertex that made the last match
pii matching(int n,vector<vi> &adj,vi &mt,int need = 1e9){
	mt.assign(n,-1);
	vi used(n,0);
	int T = 1;
	
	auto khun = [&](auto &self,int u)->bool{
		if (used[u] == T)return 0;
		used[u] = T;
 
		for (int v:adj[u]){
			if(mt[v] == -1){
				mt[v] = u;
				return 1;
			}
		}
 
		for(auto v:adj[u]){
			if(self(self,mt[v])){
				mt[v] = u;
				return 1;
			}
		}
		
		return 0;
	};
 
	int match = 0, last = -1;
	for(int i=0;i<L;i++)
		if(khun(khun,i)){
			match++;
			T++;
			last = i;
			if(match == need)break;
		}
	return {match,last};
}
