#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define fastIo() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define all(v) v.begin(), v.end() 
#define f first
#define sc second
#define DBG(x) cout<<#x<<" = "<<(x)<<endl
using namespace std;
using namespace __gnu_pbds;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll MOD=1e9+7;//998244353LL;
const ll INF=1LL<<61;
using namespace std;

int n, k;
vector<pair<ll,int>> x; // value, og position

inline ll cost(int l, int r) {       // cost of block [l, r] (1-indexed), l..r may be empty
    if (l > r) return 0;
    return x[l].f*(r-l+1);
}

vector<ll> prevDp, curDp;
vector<vector<int>> cuts; // cortes anteriores para cada posicion
vector<vector<int>> ncuts; // nuevos cortes

void solve(int ilo, int ihi, int plo, int phi) {
    if (ilo > ihi) return;
    int imid = (ilo + ihi) / 2;
    ll best = -INF; int bestp = plo;
    int hi = min(imid, phi);
    for (int p = plo; p <= hi; ++p) {
        if (prevDp[p] >= INF) continue;
        ll val = prevDp[p] + cost(p + 1, imid);
        if (val > best) { best = val; bestp = p; }
    }
    curDp[imid] = best;
    ncuts[imid] = cuts[bestp];
    ncuts[imid].push_back(bestp);
    solve(ilo, imid - 1, plo, bestp);
    solve(imid + 1, ihi, bestp, phi);
}

int main(){
    fastIo();
    cin >> n >> k;
    x.assign(n + 1, {0,0});
    cuts.assign(n+1, {});
    for (int i = 1; i <= n; ++i) {
        cin >> x[i].f;
        x[i].sc = i;
    }
    sort(all(x));

    prevDp.assign(n + 1, INF);
    prevDp[0] = 0;

    for (int j = 1; j <= k; ++j) {
        curDp.assign(n + 1, INF);
        ncuts.assign(n+1, {});
        solve(0, n, 0, n);
        prevDp.swap(curDp);
        cuts.swap(ncuts);
    }

    long double aux = n;
    cout<<fixed<<setprecision(12)<<prevDp[n]/aux<< "\n";
    int l = 0;
    vector<int> ans(n);
    for(int i=1; i<=n; i++){
        if(l < k && cuts[n][l] < i) l++;
        ans[x[i].sc-1] = l;
    }
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}
