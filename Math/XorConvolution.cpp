void xormul(vector<ll> a, vector<ll> b, vector<ll> &c) {
	ll m = (ll) a.size();
	c.resize(m);
    // Transformar a
	for (ll n = m / 2; n > 0; n /= 2)
		for (ll i = 0; i < m; i += 2 * n)
			for (ll j = 0; j < n; j++) {
				ll x = a[i + j], y = a[i + j + n];
				a[i + j] = (x + y) % MOD;
				a[i + j + n] = (x - y + MOD) % MOD;
			}
    // Transfomar b
	for (ll n = m / 2; n > 0; n /= 2)
		for (ll i = 0; i < m; i += 2 * n)
			for (ll j = 0; j < n; j++) {
				ll x = b[i + j], y = b[i + j + n];
				b[i + j] = (x + y) % MOD;
				b[i + j + n] = (x - y + MOD) % MOD;
			}
    // Obtener c transformada
	for (ll i = 0; i < m; i++)
		c[i] = a[i] * b[i] % MOD;
    // Quitar transformación a c
	for (ll n = 1; n < m; n *= 2)
		for (ll i = 0; i < m; i += 2 * n)
			for (ll j = 0; j < n; j++) {
				ll x = c[i + j], y = c[i + j + n];
				c[i + j] = (x + y) % MOD;
				c[i + j + n] = (x - y + MOD) % MOD;
			}
	ll mrev = inverse(m, MOD);
	for (ll i = 0; i < m; i++)
		c[i] = c[i] * mrev % MOD;
}
