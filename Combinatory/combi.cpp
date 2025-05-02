const int MAX = 2e6;
ll factorial[MAX+1];
ll inv[MAX+1];
 
ll binpow(ll a,ll b){
	ll ans = 1;
	a%=MOD;
	while(b){
		if(b&1)(ans*=a)%=MOD;
		(a*=a)%=MOD;
		b>>=1;
	}
	return ans;
}
 
void precalc(){
	factorial[0]=1;
	for (ll i = 1; i <= MAX; i++) {
		factorial[i] = factorial[i-1]*i%MOD;
	}
	inv[MAX] = binpow(factorial[MAX],MOD-2);
	for (ll i = MAX; i >= 1; i--) {
		inv[i-1] = inv[i]*i%MOD;
	}
}
 
ll ncr(ll a,ll b){
	return factorial[a]*inv[b]%MOD*inv[a-b]%MOD;
}
