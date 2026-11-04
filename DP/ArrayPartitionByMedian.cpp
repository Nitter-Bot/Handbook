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
vector<ll> x, pre;

inline ll S(int a, int b) {          // sum x[a..b], empty if a>b
    if (a > b) return 0;
    return pre[b] - pre[a - 1];
}

inline ll cost(int l, int r) {       // cost of block [l, r] (1-indexed), l..r may be empty
    if (l > r) return 0;
    int m = l + (r - l) / 2;         // median index
    ll leftCount = m - l, rightCount = r - m;
    return (leftCount - rightCount) * x[m] + S(m + 1, r) - S(l, m - 1);
}

vector<ll> prevDp, curDp;

void solve(int ilo, int ihi, int plo, int phi) {
    if (ilo > ihi) return;
    int imid = (ilo + ihi) / 2;
    ll best = INF; int bestp = plo;
    int hi = min(imid, phi);
    for (int p = plo; p <= hi; ++p) {
        if (prevDp[p] >= INF) continue;
        ll val = prevDp[p] + cost(p + 1, imid);
        if (val < best) { best = val; bestp = p; }
    }
    curDp[imid] = best;
    solve(ilo, imid - 1, plo, bestp);
    solve(imid + 1, ihi, bestp, phi);
}

int main(){
    fastIo();
    cin >> n >> k;
    x.assign(n + 1, 0);
    pre.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        pre[i] = pre[i - 1] + x[i];
    }

    prevDp.assign(n + 1, INF);
    prevDp[0] = 0;

    for (int j = 1; j <= k; ++j) {
        curDp.assign(n + 1, INF);
        solve(0, n, 0, n);
        prevDp.swap(curDp);
    }

    cout << prevDp[n] << "\n";
    return 0;
}
