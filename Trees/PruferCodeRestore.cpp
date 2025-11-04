int n = code.size() + 2;
vi degree(n,0);
for (int i : code)
	degree[i]++;

int ptr = 0;
while (degree[ptr] != 1)
	ptr++;

int leaf = ptr;

vector<pii> edges;
for(int v:code){
	edges.emplace_back(leaf, v);
	if (--degree[v] == 0 && v < ptr) {
		leaf = v;
	}else{
		ptr++;
		while (degree[ptr] != 1)
			ptr++;
		leaf = ptr;
	}
}

edges.emplace_back(leaf, n-1);
