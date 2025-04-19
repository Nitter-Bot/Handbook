struct Node{
	ll n = 0;
	Node operator+(Node b){return {n+b.n};}
};
 
class Fenwick_Tree{
public:
	vector<Node> tree;
	int n;
	Fenwick_Tree(int x){
		n = x+1;tree.resize(n);
	}
 
	ll sum(int r){
		r++;
		Node ans = {0};
		while(r){
			ans = ans + tree[r];
			r -= r&-r;
		}
		return ans.n;
	}
 
	void update(int id, Node val){
		id++;
		while(id < n){
			tree[id]  = tree[id]+val;
			id += id&-id;
		}
	}
};
