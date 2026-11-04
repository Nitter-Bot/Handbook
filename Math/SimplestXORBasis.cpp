vector<int> basis;
 
void add(int x) {
    // reduce x using the current basis vectors
	for (int i = 0; i < basis.size(); i++)  
		x = min(x, x ^ basis[i]);
	if (x != 0) basis.push_back(x);
}
