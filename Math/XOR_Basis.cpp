template<typename T = int, int B = 31>
struct Basis{
	T basis[B]; int sz;
	void clear() {
		memset(basis, 0, sizeof basis);
		sz = 0;
	}
	Basis(){clear();}
 
	void insert(T x) {
		for(int i=B-1;i>=0;i--){
			if(x>>i&1){
				if(basis[i])x ^= basis[i];
				else{
					basis[i] = x;
					sz++;
					break;
				}
			}
		}
	}

	bool can(T x){
		for(int i=B-1;i>=0;i--)
			x = min(x, x ^ basis[i]);
		return x == 0;
	}

	T kth(T k){
		T x = 0;
		T cnt  = ((T)1<<sz);
		for(int i=B-1;i>=0;i--){
			if(!basis[i])continue;
			if(k>(cnt>>1)){
				if (!(x>>i&1))x ^= basis[i];
				k -= (cnt>>1);
			}else{
				if (x>>i&1)x ^= basis[i];
			}
			cnt>>=1;
		}
		return x;
	}

	bool merge(Basis &b){
		bool flag = false;
		for(ll i=B-1;i>=0;i--)
			if(b.basis[i] && !insert(b.basis[i])) flag = true;
		return flag;
	}

};
