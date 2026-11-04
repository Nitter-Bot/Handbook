// Ejemplified by calculating number of subsets
// whose and gives each k
vector<ll> a(n),sosuper(1<<19), ans(1<<19);
    for(auto &x : a) cin>>x;
 
    for(auto x : a) sosuper[x]++;
    for(int i=0; i<19; i++){
        for(int j=0; j<(1<<19); j++){
            if((j&(1<<i)) == 0)
                sosuper[j] += sosuper[j|(1<<i)];
        }
    }
 
    // AND gives superset of i, if all elements are superset
    for(int i=0; i<(1<<19); i++){
        ans[i] = ( binpow(2,sosuper[i]) - 1 ) % MOD;
    }
 
 
    // Undo Sum of superset
    for(int i=18; i>=0; i--){
        for(int j=(1<<19)-1; j>=0; j--){
            if((j&(1<<i)) == 0)
                ans[j] = (ans[j] - ans[j|(1<<i)] + MOD ) % MOD;
        }
