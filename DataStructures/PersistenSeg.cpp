// Hash: #437d7b
struct Node{
	ll val;
	Node *l,*r;
	Node():val(0),l(nullptr),r(nullptr){}
}; // #736465

ll get(Node* t){
	return t?t->val:0;
} // #dea637

Node *update(Node *t,int tl,int tr,int pos,int v){
	Node* aux = new Node();
	if(tl == tr){
		aux->val = v;
		return aux;
	}

	int tm = tl+(tr-tl)/2;

	Node* l = t?t->l:nullptr;
	Node* r = t?t->r:nullptr;

	if(pos <= tm){
		aux->l = update(l,tl,tm,pos,v);
		aux->r = r;
	}else{
		aux->l = l;
		aux->r = update(r,tm+1,tr,pos,v);
	}
	
	aux->val = get(aux->l)+get(aux->r);
	return aux;
} // #a8f7ef

ll query(Node *t,int tl,int tr,int l,int r){
	if(!t || l>r)return 0;
	if(l==tl && r == tr)return t->val;
	int tm = tl+(tr-tl)/2;
	return query(t->l,tl,tm,l,min(r,tm))+query(t->r,tm+1,tr,max(l,tm+1),r);
} // #4596dc
