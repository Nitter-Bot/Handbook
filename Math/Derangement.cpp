ll der[1000006];
 
void solve(){ 
    der[0] = 1;
    der[1] = 0; 
    for(ll i=2; i<1000006; i++) 
        der[i] = ((i-1) * ((der[i-1]+der[i-2])%MOD))%MOD;
 
    int n; cin>>n;
    cout<<der[n]<<endl;
