struct Node{
	vi val;

	int search(int x){
		int l = 0, r = sz(val)-1;
		while(l<=r){
			int m = l+(r-l)/2;
			if(val[m] < x)l =m+1;
			else r = m-1;
		}
		return sz(val)-l;
	}
};

Node operator+(Node a,Node b){
	int i=0,j=0;
	Node aux;
	while (i< sz(a.val) && j<sz(b.val)){
		if (a.val[i]< b.val[j] ) aux.val.pb(a.val[i++]);
		else aux.val.pb(b.val[j++]);
	}
	while (i<sz(a.val)) aux.val.pb(a.val[i++]);
	while (j<sz(b.val)) aux.val.pb(b.val[j++]);
	return aux;
}
class Segment_Tree{
	public:
	int n,k=0;
	vector<Node> tree;
	Segment_Tree(int x = 1e5+10){
		n = x;
		while((1<<k)<n)k++;
		tree.resize(2*(1<<k)+1);
	}
	void build(vi &arr){
		for(int i=0;i<n;i++)tree[(1<<k)+i].val.pb(arr[i]);
		for(int i = (1<<k)-1; i>0;i--)tree[i] = tree[i*2]+tree[i*2+1];
	}

	void query(int a,int b,ll &ans,int i){
		a += (1<<k);
		b += (1<<k);
		while(a<=b){
			if(a%2 == 1)ans += tree[a++].search(i);
			if(b%2 == 0)ans += tree[b--].search(i);
			a/=2;
			b/=2;
		}
	}
};
