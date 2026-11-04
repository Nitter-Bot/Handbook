void solve(){  
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v; u--; v--;
        g[u][v]++;
    }
    // DP[2^n][n], works in O(2^n * n^2), means number of Hamiltonian paths
    // for that subset, starting in 1, and ending in n
    vector<vector<ll>> pos(1<<n, vector<ll> (n));
    pos[1][0] = 1;
    for(int i=2; i<(1<<n); i++){
        for(int fin=i; fin>0; fin -= fin & (-fin)){ // Remove LSB each iteration
            for(int prev = i; prev>0; prev -= prev & (-prev)){
                int lsbF = __builtin_ctz(fin);
                int lsbP = __builtin_ctz(prev);
                pos[i][lsbF] += (pos[i - (1<<lsbF)][lsbP]) * g[lsbP][lsbF];
                pos[i][lsbF] %= MOD;
            }
        }
    }
    cout<<pos[(1<<n)-1][n-1]<<endl;
}
