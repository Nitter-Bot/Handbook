// Hash: #545fdb
struct Node{
	vi val;

	int search(int x){
		// cnt >= x
		auto it = lower_bound(all(val), x);
		return val.end() - it; // #c83330
		// cnt > x
		//auto it = upper_bound(all(val), x);
		//return val.end() - it; // #fe1bbd
		// cnt == x
		//auto l_it = lower_bound(all(val), x);
		//auto u_it = upper_bound(all(val), x);
		//return u_it - l_it; // #281439
	}
};

Node operator+(Node a,Node b){
	Node aux;
	aux.val.resize(sz(a.val) + sz(b.val));
	merge(all(a.val), all(b.val), aux.val.begin());
} // #086024
