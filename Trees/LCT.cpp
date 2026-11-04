struct Node{
	Node *p = 0, *pp = 0, *c[2];
	bool flip = 0;
	int id = -1,sz = 0;
	Node() { c[0] = c[1] = 0; fix(); }
	
	void fix(){
		sz = 1;
		if (c[0]){
			c[0]->p = this;
			sz += c[0]->sz;
		}
		if (c[1]){
			c[1]->p = this;
			sz += c[1]->sz;
		}
		// (+ update sum of subtree elements etc. if wanted)
	}

	void pushFlip() {
		if (!flip) return;
		flip = 0; swap(c[0], c[1]);
		if (c[0]) c[0]->flip ^= 1;
		if (c[1]) c[1]->flip ^= 1;
	}
	
	int up() { return p ? p->c[1] == this : -1; }
	
	void rot(int i, int b) {
		int h = i ^ b;
		Node *x = c[i], *y = b == 2 ? x : x->c[h], *z = b ? y : x;
		if ((y->p = p)) p->c[up()] = y;
		c[i] = z->c[i ^ 1];
		if (b < 2) {
			x->c[h] = y->c[h ^ 1];
			y->c[h ^ 1] = x;
		}
		z->c[i ^ 1] = this;
		fix(); x->fix(); y->fix();
		if (p) p->fix();
		swap(pp, y->pp);
	}

	void splay() { /// Splay this up to the root. Always finishes without flip set.
		for (pushFlip(); p; ) {
			if (p->p) p->p->pushFlip();
			p->pushFlip(); pushFlip();
			int c1 = up(), c2 = p->up();
			if (c2 == -1) p->rot(c1, 2);
			else p->p->rot(c2, c1 != c2);
		}
	}
	
	Node* first() { /// Return the min element of the subtree rooted at this, splayed to the top.
		pushFlip();
		return c[0] ? c[0]->first() : (splay(), this);
	}
};

struct LCT{
	vector<Node> node;
	LCT(int N):node(N){
		for(int i=0;i<N;i++)node[i].id = i;
	}

	void link(int u,int v){
		makeRoot(&node[u]);
		node[u].pp = &node[v];
	}

	void cut(int u, int v){ // remove an edge (u, v)
		Node *x = &node[u], *top = &node[v];
		makeRoot(top); x->splay();
		assert(top == (x->pp ?: x->c[0]));
		if (x->pp) x->pp = 0;
		else{
			x->c[0] = top->p = 0;
			x->fix();
		}
	}

	void cut(int u){
		access(&node[u]);
		node[u].splay();
		if(node[u].c[0]){
			node[u].c[0]->p = 0;
			node[u].c[0] = 0;
			node[u].fix();
		}
	}
	
	Node* findRoot(int u){
		return access(&node[u])->first();
	}

	bool connected(int u, int v) { // are u, v in the same tree?
		return findRoot(u)== findRoot(v);
	}

	void makeRoot(Node* u){ /// Move u to root of represented tree.
		access(u);
		u->splay();
		if(u->c[0]){
			u->c[0]->p = 0;
			u->c[0]->flip ^= 1;
			u->c[0]->pp = u;
			u->c[0] = 0;
			u->fix();
		}
	}

	Node* access(Node* u){ /// Move u to root aux tree. Return the root of the root aux tree.
		u->splay();

		if(u->c[1]){
			u->c[1]->p = 0;
			u->c[1]->pp = u;
			u->c[1] = 0;
			u->fix();
		}

		while (Node* pp = u->pp){
			pp->splay(); u->pp = 0;
			if (pp->c[1]){
				pp->c[1]->p = 0;
				pp->c[1]->pp = pp;
			}
			pp->c[1] = u; pp->fix(); u = pp;
		}
		return u;
	}
	
	int depth(int u){
		access(&node[u]);
		node[u].splay();
		node[u].fix();
		return node[u].c[0]->sz;
	}

	Node* lca(int u,int v){
		access(&node[u]);
		return access(&node[v]);
	}
};


