struct Line{
	ll m, c;
	ll eval(ll x){return m * x + c;}
};

struct Node{
	Line line;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(Line line) : line(line) {}

	Node* add(Node* node, Line nw, int tl, int tr){
		if(!node){return new Node(nw);}
		int tm = tl+(tr-tl)/2;
		
		if(nw.eval(tm) > node->line.eval(tm)){swap(nw,node->line);}
		
		if(tl==tr){return node;}
		
		if(nw.eval(tl)>node->line.eval(tl)){
		    node->left = add(node->left,nw,tl,tm);
		}else{
		    node->right = add(node->right,nw,tm+1,tr);
		}
		return node;
	}

	Node* add(Node* node, Line nw, int tl, int tr, int l, int r){
		if(l>tr||r<tl){return node;}
		if(!node){node = new Node({0,-INF64});}
        
		if(l<=tl&&tr<=r){
			return add(node,nw,tl,tr);
		}
        
		int tm = tl+(tr-tl)/2;
		node->left = add(node->left,nw,tl,tm,l,r);
		node->right = add(node->right,nw,tm+1,tr,l,r);
		return node;
	}

	ll query(Node* node, ll x, int tl, int tr){
		if(!node){return -INF64;}
		int tm = tl+(tr-tl)/2;

		if(x<=tm) return max(query(node->left,x,tl,tm),node->line.eval(x));
		else return max(query(node->right,x,tm+1,tr),node->line.eval(x));
	}
};

struct LiChaoTree{
	int tl, tr;
	Node* root;
	LiChaoTree():tl(-INF/2), tr(INF/2),root(nullptr){}
	LiChaoTree(int tl, int tr) : tl(tl), tr(tr){
		root = new Node({0, INF64});
	}

	void add(Line line, int l, int r){
		root -> add(root,line, tl, tr, l, r);
	}
	ll query(ll x){
		return root->query(root,x,tl,tr);
	}
};
