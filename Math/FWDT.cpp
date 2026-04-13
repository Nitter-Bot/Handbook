const int MOD = 1e9+7;
const int inv2 = (MOD + 1) >> 1;
#define M (1 << 20)
#define OR 0
#define AND 1
#define XOR 2
 
int P1[M],P2[M];
void wt(int *a, int n, int flag = XOR){
	if (n == 0) return;
	int m = n / 2;
	wt(a, m, flag); wt(a + m, m, flag);
	for(int i = 0; i < m; i++){
		int x = a[i], y = a[i + m];
		if (flag == OR) a[i] = x, a[i + m] = (x + y) % MOD;
		if (flag == AND) a[i] = (x + y) % MOD, a[i + m] = y;
		if (flag == XOR) a[i] = (x + y) % MOD, a[i + m] = (x - y + MOD) % MOD;
	}
}
void iwt(int* a, int n, int flag = XOR) {
	if (n == 0) return;
	int m = n / 2;
	iwt(a, m, flag); iwt(a + m, m, flag);
	for(int i = 0; i < m; i++){
	int x = a[i], y = a[i + m];
		if (flag == OR) a[i] = x, a[i + m] = (y - x + MOD) % MOD;
		if (flag == AND) a[i] = (x - y + MOD) % MOD, a[i + m] = y;
		if (flag == XOR) a[i] = 1LL * (x + y) * inv2 % MOD, a[i + m] = 1LL * (x - y + MOD) * inv2 % MOD; // replace inv2 by >>1 if not required
	}
}

vector<int> multiply(int n, vector<int> &A, vector<int> &B, int flag = XOR) {
	assert(__builtin_popcount(n) == 1);
	A.resize(n); B.resize(n);
	for(int i = 0; i < n; i++) P1[i] = A[i];
	for(int i = 0; i < n; i++) P2[i] = B[i];
	wt(P1, n, flag); wt(P2, n, flag);
	for (int i = 0; i < n; i++) P1[i] = 1LL * P1[i] * P2[i] % MOD;
	iwt(P1, n, flag);
	return vector<int> (P1, P1 + n);
}
