// Hash: b34e73
struct BIT{
	vll bit;
	int n;
	BIT(int x){n = x+1;bit.assign(n,0);} // #69335b

	ll get(int x){
		ll ans =0;
		for(;x;x-=x&-x)ans+=bit[x];
		return ans;
	} // #781a0f
 
	void update(int x, ll val){
		for(;x<n;x+=x&-x)
			bit[x] += val;
	} // #4e7832
};
