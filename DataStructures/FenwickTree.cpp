struct BIT{
	vll bit;
	int n;
	BIT(int x){n = x+1;bit.assign(n);}

	ll get(int x){
		ll ans =0;
		for(;x;x-=x&-x)ans+=bit[x];
		return ans;
	}
 
	void update(int x, ll val){
		for(;x<n;x+=x&-x)
			bit[x] += val;
	}
};
