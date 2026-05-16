// TOTAL: c88465
struct Node{
	ll val = 0;
}; // #6368df
Node operator+(Node a,Node b){return {a.val+b.val};}
class Segment_Tree{
public:
	int n;
	vector<Node> tree;

	Segment_Tree(int x = 1e5+10){
		n = x;
		tree.resize(2*n+1);
	} // #9ba7b9

	void update(int p, ll val){
		for(tree[p+=n] = {val};p>1;p>>=1)
			tree[p>>1] = tree[p]+tree[p^1];
		//for (tree[p+=n] = {val};p>>= 1;)
		//	t[p] = t[p<<1]+t[p<<1|1]; // #9c6ca8
	} // #fd122a
	ll query(int l,int r){
		Node s;
		for(l+=n,r+=n ; l<r ; l>>=1 , r>>=1){
			if(l&1)s = s+ tree[l++];
			if(r&1)s = s+ tree[--r];
		}
		return s.val;
	} // #409731
}; // #19ff3f
