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

template <typename T> using oset = tree<
    T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update
>;

const ll MOD=1e9+7; //998244353LL;
const ll INF=1LL<<60;

string limpiar(const string& s) {
    size_t pos = s.find_first_not_of('0');
    return (pos == string::npos) ? "0" : s.substr(pos);
}

string mayor(const string& a, const string& b) {
    string x = limpiar(a), y = limpiar(b);
    if (x.size() != y.size()) return x.size() > y.size() ? x : y;
    return x >= y ? x : y;
}

string sumar(const string& a, const string& b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1, acarreo = 0;
    while (i >= 0 || j >= 0 || acarreo) {
        int suma = acarreo;
        if (i >= 0) suma += a[i--] - '0';
        if (j >= 0) suma += b[j--] - '0';
        res.push_back('0' + suma % 10);
        acarreo = suma / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string restar(const string& a, const string& b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1, prestamo = 0;
    while (i >= 0) {
        int d = (a[i--] - '0') - prestamo;
        if (j >= 0) d -= b[j--] - '0';
        if (d < 0) { d += 10; prestamo = 1; }
        else prestamo = 0;
        res.push_back('0' + d);
    }
    reverse(res.begin(), res.end());
    return limpiar(res);
}

string multiplicar(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    string res(n + m, '0');
    for (int i = n - 1; i >= 0; i--) {
        int acarreo = 0;
        for (int j = m - 1; j >= 0; j--) {
            int prod = (a[i] - '0') * (b[j] - '0') + (res[i + j + 1] - '0') + acarreo;
            res[i + j + 1] = '0' + prod % 10;
            acarreo = prod / 10;
        }
        res[i] += acarreo;
    }
    return limpiar(res);
}

void solve(){
    return;
}

int main(){
    fastIo();
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}
