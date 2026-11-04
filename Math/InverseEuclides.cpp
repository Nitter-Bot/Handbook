// Inverso modular con algoritmo extendido de euclides
ll inverse(ll x, ll mod) {
	return x == 1 ? 1 : mod - mod / x * inverse(mod % x, mod) % mod;
}
