ll binpow(ll a,ll b){
  a%=MOD;
  ll ans = 1;
  while(b){
    if(b&1)(ans*=a)%=MOD;
    (a*=a)%=MOD;
    b>>=1;
  }
  return ans;
}
