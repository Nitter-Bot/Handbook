// Hash: 2e457c
const int MAX = 2e6;
ll factorial[MAX+1];
ll inv[MAX+1]; // #d459d3

ll binpow(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1)res = res*a%MOD;
		a = a*a%MOD;
		b>>=1;
	}
	return res;
} // #89684f
 
void precalc(){
	factorial[0]=1;
	for (ll i = 1; i <= MAX; i++) {
		factorial[i] = factorial[i-1]*i%MOD;
	}
	inv[MAX] = binpow(factorial[MAX],MOD-2);
	for (ll i = MAX; i >= 1; i--) {
		inv[i-1] = inv[i]*i%MOD;
	}
} // #c4e465

ll ncr(ll a,ll b){
	return factorial[a]*inv[b]%MOD*inv[a-b]%MOD;
} // #f2f007
