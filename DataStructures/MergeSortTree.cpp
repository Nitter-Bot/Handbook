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
//Call segment Tree
