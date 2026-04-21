typedef ll ftype;
typedef complex<ftype> point;
#define x real
#define y imag
const ll MOD=1e9+7; //998244353LL;
const ll INF=1LL<<60;
const int maxn = 2e5;
point line[4 * maxn];
ftype dot(point a, point b) {
return (conj(a) * b).x();
}
ftype f(point a, ftype x) {
return dot(a, {x, 1});
}
void add_line(point nw, int v, int l, int r, int
lf, int rf) {
int m = (l + r) / 2;
if(rf < l || r <= lf) return;
if(l < lf || rf < r-1){
add_line(nw, 2 * v, l, m, lf, rf);
add_line(nw, 2 * v + 1, m, r, lf, rf);
return;
}
bool lef = f(nw, l) < f(line[v], l);
bool mid = f(nw, m) < f(line[v], m);
if(!mid) {
swap(line[v], nw);
}
if(r - l == 1) {
return;
} else if(lef != mid) {
add_line(nw, 2 * v, l, m, lf, rf);
} else {
add_line(nw, 2 * v + 1, m, r, lf, rf);
}
}
ftype get(int x, int v, int l, int r) {
int m = (l + r) / 2;
if(r - l == 1) {
return f(line[v], x);
} else if(x < m) {
return max(f(line[v], x), get(x, 2 * v,
l, m));
} else {
return max(f(line[v], x), get(x, 2 * v +
1, m, r));
}
