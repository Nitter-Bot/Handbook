ll binpow(ll n,ll k,const int mod){
	ll res = 1;
	n%=mod;
	while(k){
		if(k&1)(res*=n)%=mod;
		(n*=n)%=mod;
		k>>=1;
	}
	return res;
}

const int MOD1 = 127657753,MOD2 = 987654319;
const int P1 = 137,P2 = 277;
const int MAX = 1e6+9;

vector<pll> P(MAX),I_P(MAX);

void calc(){
	P[0] = {1,1};
	for(int i=1;i<MAX;i++){
		P[i].F = P[i-1].F*P1%MOD1;
		P[i].S = P[i-1].S*P2%MOD2;
	}
	int i1 = binpow(P1,MOD1-2,MOD1);
	int i2 = binpow(P2,MOD2-2,MOD2);
	I_P[0] = {1,1};
	for(int i=1;i<MAX;i++){
		I_P[i].F = I_P[i-1].F*i1%MOD1;
		I_P[i].S = I_P[i-1].S*i2%MOD2;
	}
}

struct Hashing {
	int n;
	string s; // 0 - indexed
	vector<pll> hs; // 1 - indexed
	
	Hashing(string _s) {
		n = _s.size();
		s = _s;
		hs.emplace_back(0, 0);
		for (int i = 0; i < n; i++) {
			pll p;
			p.F = (hs[i].F + P[i].F * (s[i]-'a'+1) % MOD1) % MOD1;
			p.S = (hs[i].S + P[i].S * (s[i]-'a'+1) % MOD2) % MOD2;
			hs.push_back(p);
		}
	}

	pll get_hash(int l, int r) { // 1 - indexed
		pll ans;
		ans.F = (hs[r].F - hs[l - 1].F+ MOD1) * 1LL * I_P[l - 1].F% MOD1;
		ans.S = (hs[r].S - hs[l - 1].S+ MOD2) * 1LL * I_P[l - 1].S% MOD2;
		return ans;
	}
};

