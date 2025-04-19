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

	void build(vi &arr){
		for(int i=0;i<n;i++)tree[n+i] = {arr[i]};
		for(int i = n-1; i>0;i--)tree[i] = tree[i*2]+tree[i*2+1];
	}

	void update(int p, ll val){
		for(t[p+=n] = {val};p>1;p>>=1)tree[p>>1] = tree[p]+t[p^1];
	}

	ll query(int l,int r){
		Node s;
		for(l+=n,r+=n ; l<r ; l>>=1 , r>>=1)
			if(l&1)s = s+ tree[l++];
			if(r&1)s = s+ tree[--r];
		}
		return s.val;
	}
};
