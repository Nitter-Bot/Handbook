void ntt(vll &a){
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vll rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, binpow(root, MOD >> s)};
		for(int i=k;i<2*k;i++)
			rt[i] = rt[i / 2] * z[i & 1] % MOD;
	}
	vi rev(n);
	for(int i=0;i<n;i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	for(int i=0;i<n;i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) 
			for(int j=0;j<k;j++){
			ll z = rt[j + k] * a[i + j + k] % MOD, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? MOD : 0);
			ai += (ai + z >= MOD ? z - MOD : z);
		}
}

vll conv(const vll &a, const vll &b){
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s),
	    n = 1 << B;
	int inv = binpow(n, MOD - 2);
	vll L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	for(int i=0;i<n;i++)
		out[-i & (n - 1)] = (ll)L[i] * R[i] % MOD * inv % MOD;
	ntt(out);
	return {out.begin(), out.begin() + s};
}
