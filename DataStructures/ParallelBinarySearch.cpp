// Parallel binary search using DSU as example
// answers first moment two nodes are reachable
// adding edges one by one
int main(){
    int n,m,q; cin>>n>>m>>q;
    vector<pair<int,int>> edges(m+1); // 1 indexed
    for(int i=1; i<=m; i++)
        cin>>edges[i].f>>edges[i].sc; 
    
    vector<pair<int,int>> qs(q); // 0 indexed
    for(int i=0; i<q; i++)
        cin>>qs[i].f>>qs[i].sc;
    

    // Parallel binary search
    int steps = log2(m)+1;
    vector<int> L(q,0), R(q,m);
    vector<vector<int>> check(m+1); // 0 is before every edge
    vector<int> ans(q,-1);
    for(int _=0; _<steps; _++){
        // Set mid to check for every query
        for(int i=0; i<q; i++){
            if(L[i] <= R[i]){
                int mid = (L[i]+R[i]) / 2;
                check[mid].push_back(i);
            }
        }
        // New DSU
        DSU dsu(n);
        // Go through all edges linearly, check queries on each
        for(int i=0; i<=m; i++){
            // Add ith edge 
            if(i > 0) dsu.merge(edges[i].f,edges[i].sc);
            while(check[i].size()){
                int x = check[i].back(); check[i].pop_back();
                if(dsu.same(qs[x].f, qs[x].sc)){
                    R[x] = i-1;
                    ans[x] = i; 
                }else{
                    L[x] = i+1;
                }
            }
        }
    }

    for(auto x : ans) cout<<x<<endl;
    return 0;
}
