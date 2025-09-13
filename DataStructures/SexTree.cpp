struct Node{
	ll val = 0;
};
Node operator+(Node a,Node b){return {a.val+b.val};}
class Segment_Tree{
public:
	int n;
	vector<Node> tree;

	Segment_Tree(int x = 1e5+10){
		n = x;
		tree.resize(2*n+1);
	}

	void update(int p, ll val){
		for(tree[p+=n] = {val};p>1;p>>=1)
			tree[p>>1] = tree[p]+tree[p^1];
	}

	ll query(int l,int r){
		Node s;
		for(l+=n,r+=n ; l<r ; l>>=1 , r>>=1){
			if(l&1)s = s+ tree[l++];
			if(r&1)s = s+ tree[--r];
		}
		return s.val;
	}
};
