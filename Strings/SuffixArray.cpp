struct suffix{
	int index;
	pii rank;
	bool operator<(suffix b){return rank<b.rank;}
	bool operator>(suffix b){return rank>b.rank;}
};

class Suffix_Array{
	public:
	string s;int n;
	vector<suffix> suffixes;
	vi lcp;
	Suffix_Array(string x){
		s = x+"$";
		n = sz(s);
		suffixes.resize(n);
	}


	void radix_sort(vector<suffix> &suff){
		for(int i: vi{2,1}){
			auto key = [&](const suffix &x){
				return i == 1?x.rank.F:x.rank.S;
			};
		
			int mx = 0;
			for (const auto &i:suff) { mx = max(mx, key(i)); }
			vector<int> occs(mx + 1);
			for (const auto &i:suff)occs[key(i)]++; 
			vector<int> start(mx + 1);
			for (int i=1;i<=mx; i++) start[i] = start[i-1]+occs[i-1];

			vector<suffix> new_arr(suff.size());
			for (const auto &i : suff) {
				new_arr[start[key(i)]] = i;
				start[key(i)]++;
			}
			suff = new_arr;
		}
	}

	void build(){
		for(int i=0;i<n;i++)suffixes[i].index = i , suffixes[i].rank = {s[i],(i+1<n?s[i+1]:-1)};
		sort(all(suffixes));
		vi equiv(n);

		for(int i=1;i<n;i++){
			auto c_val = suffixes[i].rank;
			int cs = suffixes[i].index;
			auto  p_val = suffixes[i - 1].rank;
			int ps = suffixes[i-1].index;
			equiv[cs] = equiv[ps] + (c_val > p_val);
		}

		for(int cmp_ant = 1;cmp_ant <n; cmp_ant<<=1){
			for(auto &x:suffixes)
				x.rank = {equiv[x.index],equiv[(x.index+cmp_ant)%n]};
			
			//Std sort O(nlognlogn)	Radix Sort O(nlogn)
			radix_sort(suffixes);
			
			for(int i=1;i<n;i++){
				auto c_val = suffixes[i].rank;
				int cs = suffixes[i].index;
				auto  p_val = suffixes[i - 1].rank;
				int ps = suffixes[i-1].index;
				equiv[cs] = equiv[ps] + (c_val > p_val);
			}
		}
	}

	void build_lcp(){
		vector<int> suff_ind(n);
		for (int i = 0; i < n; i++)suff_ind[suffixes[i].index] = i;
		lcp.resize(n-1);
		int start_at = 0;
		for (int i = 0; i < n - 1; i++) {
			int prev = suffixes[suff_ind[i] - 1].index;
			int curr_cmp = start_at;
			while (s[i + curr_cmp] == s[prev + curr_cmp])curr_cmp++;
			lcp[suff_ind[i] - 1] = curr_cmp;
			start_at = max(curr_cmp - 1, 0);
		}
	}

	void show(){
		for(int i=0;i<n;i++)cout << suffixes[i].index << " \n"[(i+1)==n];
	}
};
