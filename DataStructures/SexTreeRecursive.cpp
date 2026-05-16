//Hash: #f94ebe
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
		tree.resize(4*n+1);
	} // #f71c07
	
	void update(int v, int tl, int tr, int pos, int new_val){
		if(tl == tr){
			tree[v] = {new_val};
			return;
		}

		int tm = tl+(tr-tl)/2;

		if (pos<=tm)update(v<<1,tl,tm,pos,new_val);
		else update((v<<1)+1,tm+1,tr,pos,new_val);

		tree[v] = tree[v<<1] + tree[(v<<1)+1];
	} // #b8d734

	Node query(int v, int tl, int tr, int l, int r){
		if (l > r)return {0};
		if (l==tl && r==tr)return tree[v];
		
		int tm = tl+(tr-tl)/2;
		return query(v<<1,tl,tm,l,min(r,tm))+query((v<<1)+1,tm+1,tr,max(l,tm+1),r);
	} // #3499b3
};
