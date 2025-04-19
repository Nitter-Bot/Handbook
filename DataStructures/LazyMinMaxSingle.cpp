struct Node{
	ll val = 0;
};

struct LazyNode{
	ll val = 0;
	bool can(){return val!=0;}
};

Node operator+(Node a,LazyNode b){return {a.val+b.val};}
Node operator+(Node a,Node b){return {a.val+b.val};}
LazyNode operator+(LazyNode a,LazyNode b){return {a.val+b.val};}

class Segment_Tree{
private:
	int n,h;

	void apply(int p, ll val){
		tree[p].val += val;
		if(p < n)d[p].val += val;
	}

	void build_lazy(int p){
		while(p>1){
			p >>= 1;
			tree[p] = (tree[p*2]+tree[p*2+1])+d[p];
		}
	}

	void push(int p){
		for(int s = h;s>0;--s){
			int i = p>>s;
			if(d[i].can()){
				apply(2*i,d[i].val);
				apply(2*i+1,d[i].val);
				d[i].val = 0;
			}
		}
	}

public:
	vector<Node> tree;
	vector<LazyNode> d;
	Segment_Tree(int x = 1e5+10){
		n = x;
		tree.resize(2*n+1);
		d.resize(n+1);
		h = sizeof(int)*8 - __builtin_clz(n);
	}
	void build(vi &arr){
		for(int i=0;i<n;i++)tree[n+i] = {arr[i]};
		for(int i = n-1; i>0;i--)tree[i] = tree[i*2]+tree[i*2+1];
	}
	ll query(int l, int r){
		l += n;r+=n;
		push(l);
		push(r-1);
		Node s;
		for(;l<r; l>>=1,r>>=1){
			if(l&1)s = s+ tree[l++];
			if(r&1)s = s+ tree[--r];
		}
		return s.val;
	}

	void range_increment(int l,int r,ll val){
		l += n;
		r += n;
		int l0=l,r0=r;
		
		for(;l<r;l>>=1,r>>=1){
			if(l&1)apply(l++,val);
			if(r&1)apply(--r,val);
		}
		build_lazy(l0);
		build_lazy(r0-1);
	}
	
};
