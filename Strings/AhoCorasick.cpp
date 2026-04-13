struct AC{
	static const int K = 26;
	struct Node{
		int ch[K];
		int fail;
		int last_m;
		vi id;
		Node(){
			memset(ch,0,sizeof(ch));
			fail = last_m = 0;
		}
	};

	vector<Node> t;

	AC(){t.emplace_back();}

	void insert(string& s, int id){
		int u = 0;
		for(char c:s){
			int v = c-'a';
			if(!t[u].ch[v]){
				t[u].ch[v] = sz(t);
				t.emplace_back();
			}
			u = t[u].ch[v];
		}
		t[u].id.push_back(id);
	}
	
	void build(){
		queue<int> q;
		for(int i=0;i<K;i++)
			if (t[0].ch[i]) q.push(t[0].ch[i]);

		while(!q.empty()){
			int u=q.front();q.pop();
			int f = t[u].fail;
			t[u].last_m = t[f].id.empty() ? t[f].last_m:f;

			for(int i=0;i<K;i++){
				int &v = t[u].ch[i];
				if(v){
					t[v].fail = t[f].ch[i];
					q.push(v);
				}else v = t[f].ch[i];
			}
		}
	}
};
