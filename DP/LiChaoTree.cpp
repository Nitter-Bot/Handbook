struct LiChao {
    using ftype = ll;
    using point = complex<ftype>;

    static const int Xmax = 1e6+1; // Adjust this

    vector<point> line;
    bool isMin;

    #define x real
    #define y imag

    LiChao(bool minQuery = true) : isMin(minQuery) { 
        line.assign(4 * Xmax, {0, isMin ? INF : 0});
    }

    ftype dot(point a, point b) {
        return (conj(a) * b).x();
    }

    ftype f(point a, ftype x) {
        return dot(a, {x, 1});
    }

    // nw acts in range [lf, rf], each node covers [l, r)
    void add_line(point nw, int v = 1, int l = 0, int r = Xmax, int lf = 0, int rf = Xmax - 1) {
        int m = (l + r) / 2;

        if (rf < l || r <= lf) return;

        if (l < lf || rf < r - 1) {
            add_line(nw, 2 * v, l, m, lf, rf);
            add_line(nw, 2 * v + 1, m, r, lf, rf);
            return;
        }

        bool lef = isMin
            ? f(nw, l) < f(line[v], l)
            : f(nw, l) > f(line[v], l);

        bool mid = isMin
            ? f(nw, m) < f(line[v], m)
            : f(nw, m) > f(line[v], m);

        if (mid) swap(line[v], nw);

        if (r - l == 1) {
            return;
        } else if (lef != mid) {
            add_line(nw, 2 * v, l, m, lf, rf);
        } else {
            add_line(nw, 2 * v + 1, m, r, lf, rf);
        }
    }

    ftype get(int x, int v = 1, int l = 0, int r = Xmax) {
        int m = (l + r) / 2;

        if (r - l == 1) {
            return f(line[v], x);
        }

        if (x < m) {
            ftype res = get(x, 2 * v, l, m);
            return isMin
                ? min(f(line[v], x), res)
                : max(f(line[v], x), res);
        } else {
            ftype res = get(x, 2 * v + 1, m, r);
            return isMin
                ? min(f(line[v], x), res)
                : max(f(line[v], x), res);
        }
    }

    #undef x
    #undef y
};
