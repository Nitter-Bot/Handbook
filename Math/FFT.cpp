typedef complex<double> base;

void fft(vector<base> &p, bool inv = 0) {
	int n = p.size(), i = 0;
	for(int j = 1; j < n - 1; ++j) {
		for(int k = n >> 1; k > (i ^= k); k >>= 1);
		if(j < i) swap(p[i], p[j]);
	}
	
	for(int l = 1, m; (m = l << 1) <= n; l <<= 1) {
		double ang = 2 * PI / m *(inv?1.0:-1.0);
		base wn(cos(ang),sin(ang));
		for(int i = 0; i < n; i += m) {
			base w(1,0);
			for(int j = i, k = i + l; j < k; ++j, w *= wn) {
				base t = w * p[j + l];
				p[j + l] = p[j] - t;
				p[j] = p[j] + t;
			}
		}
	}
	
	if(inv) for(int i = 0; i < n; ++i) p[i] /= n;
}
vector<ll> multiply(vi &a, vi &b) {
	int n = a.size(), m = b.size(), t = n + m - 1, sz = 1;
	while(sz < t) sz <<= 1;
	vector<base> x(sz), y(sz);
	for(int i = 0; i < n; ++i) x[i] = base(a[i], 0);
	for(int i = 0; i < m; ++i) y[i] = base(b[i], 0);
	fft(x), fft(y);
	for(int i = 0; i < sz; ++i) x[i] *= y[i];
	fft(x, 1);
	vector<ll> ret(sz);
	for(int i = 0; i < sz; ++i) ret[i] = (ll)round(x[i].real());
	while((int)ret.size() > 1 && ret.back() == 0) ret.pop_back();
	return ret;
}
