int reduce(array<int, 30> &b, int x) {  
    // reducing x using basis vectors b
	for (int i = 30 - 1; i >= 0; i--) {
        // check if the ith bit is set
		if (x & (1 << i)) { 
			x ^= b[i];
		}
	}
	return x;
}

// Returns true if it is independent
bool add(array<int, 30> &b, int x) {
    // reduce x using current basis
	x = reduce(b, x);  
	if (x != 0) {
		for (int i = 30 - 1; i >= 0; i--) {
      // add x to the basis if it is independent
			if (x & (1 << i)) {
				b[i] = x;  
				return true;
			}
		}
	}
	return false;
}
