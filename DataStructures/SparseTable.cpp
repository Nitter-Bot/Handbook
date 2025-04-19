struct Node{
	int val = 0;
	Node operator+(Node b){return {__gcd(val,b.val)};}
};

class SparseTable{
	public:
	vector<vector<Node>> sparse;

	SparseTable(int n=2e5+10){
		sparse.assign(n , vector<Node> (log2(n)+1));
	}

	void build(const vi &a){
		for(int i=0;i<sz(a);i++)
			sparse[i][0] = {a[i]};
		
		for(int j=1;(1<<j)<=sz(a);j++)
			for(int i=0;i+(1<<j)-1 <sz(a);i++)
				sparse[i][j]= sparse[i][j-1]+sparse[i+(1<<(j-1))][j-1];
	}

	int query(int l, int r){
		int len = r-l+1;
		int k = log2(len);
		return (sparse[l][k]+sparse[r-(1<<k)+1][k]).val;
	}

};
