void solve(){
int n,k; cin>>n>>k;
vector<ll> acu(1<<k), sos(1<<k);
string s;
for(int i=0; i<n ; i++){
cin>>s;
sos[stoi(s,nullptr, 2)]++;
}
for (int i = 0; i < k; i++) {
for (int j = 0; j < (1 << k); j++) {
if ((j >> i) & 1) {
sos[j] += sos[j - (1 << i)];
}
}
}
for(int i=0; i<(1<<k); i++) {
if(i<3) acu[i]=0;
acu[i] = ((sos[i])*(sos[i]-1)*(sos[i]-2))/6;
}
for (int i = k - 1; i >= 0; i--) {
for (int j = (1 << k) - 1; j >= 0; j--) {
if ((j >> i) & 1) {
acu[j] -= acu[j - (1 << i)];
}
}
}
int m; cin>>m;
for(int i=0; i<m; i++){
cin>>s;
cout<<acu[stoi(s,nullptr, 2)]<<endl;
}
}
