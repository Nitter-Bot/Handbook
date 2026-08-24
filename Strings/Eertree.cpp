struct Eertree{
	struct Node{
		int nxt[26],len,st,en,link,cnt,oc;
	};//f0c5da

	vector<Node> t;
	string s;
	int sz, last;
	Eertree(){}//24d5fc
	
	Eertree(string _s){
		s = _s;
		int n = sz(s);
		t.resize(n+5);
		sz = 2, last = 2;
		t[1].len = -1, t[1].link = 1;
		t[2].len = 0 , t[2].link = 1;
	}//1fe603

	int get_link(int u,int pos){
		while(pos-1-t[u].len<0 || s[pos-1-t[u].len] != s[pos])
			u = t[u].link;
		return u;
	}//72a63c

	bool add(int pos){
		int ch = s[pos]-'a';
		int cur = get_link(last,pos);
		
		if(t[cur].nxt[ch]){
			last = t[cur].nxt[ch];
			t[last].oc++;
			return 0;
		}//4c7cf1

		sz++;
		t[sz].len = t[cur].len+2;
		t[sz].en = pos;
		t[sz].st = pos-t[sz].len+1;//3b0156

		if(t[sz].len == 1)t[sz].link = 2;
		else t[sz].link = t[get_link(t[cur].link,pos)].nxt[ch];

		t[sz].cnt = t[t[sz].link].cnt+1;
		t[sz].oc = 1;
		t[cur].nxt[ch] = sz;
		last = sz;
		return 1;//e1a942
	}//4b0fbf
	
	void calc_occurrences(){
		for(int i=sz;i>2;i--)
			t[t[i].link].oc += t[i].oc;
	}//38a897

	void show(){
		for(int i=3;i<=sz;i++)cout << s.substr(t[i].st,t[i].len) << '\n';
	}//996a3b

};//5bf93b
