template<int M> vll convMod(const vll &a, const vll &b) {
	if(a.empty() || b.empty()) return {};
	vll res(sz(a) + sz(b) - 1);
	int B = 32 - __builtin_clz(sz(res)), n = 1 << B, cut = int(sqrt(M));
	vector<base> L(n), R(n), outs(n), outl(n);
	for(int i = 0; i < sz(a); i++) L[i] = base((int)a[i] / cut, (int)a[i] % cut);
	for(int i = 0; i < sz(b); i++) R[i] = base((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	for(int i = 0; i < n; i++) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	for(int i = 0; i < sz(res); i++) {
		ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
		ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
		res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
	}
	return res;
}
