void remove(idx);  // TODO: remove value at idx from data structure
void add(idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure
 // #86ec16
int block_size;

struct Query{
	int l, r, idx;
	bool operator<(Query other) const
	{
		return make_pair(l / block_size, r) < 
			make_pair(other.l / block_size, other.r);
	}
}; // #8e89a9

//in main

sort(all(queries));

// TODO: initialize data structure

int cur_l = 0;
int cur_r = -1;
// invariant: data structure will always reflect the range [cur_l, cur_r]
for(Query q:queries){
	while(cur_l > q.l)
		add(--cur_l);
	
	while(cur_r < q.r)
		add(++cur_r);
	
	while(cur_l < q.l)
		remove(cur_l++);
	
	while(cur_r > q.r)
		remove(cur_r--);
	
	answers[q.idx] = get_answer();
} // #50d13b
