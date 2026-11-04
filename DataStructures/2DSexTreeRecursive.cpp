int t[4005][4005];
int a[1000][1000];
int n;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void build_x(int vx, int lx, int rx) {
    if (rx != lx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, n-1);
}

int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ry < tly || try_ < ly) 
        return 0;
    if (ly <= tly && try_ <= ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy*2, tly, tmy, ly, ry)
        + sum_y(vx, vy*2+1, tmy+1, try_, ly, ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (rx < tlx || trx < lx)
        return 0;
    if (lx <= tlx && trx <= rx)
        return sum_y(vx, 1, 0, n-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx*2, tlx, tmx, lx, rx, ly, ry)
        + sum_x(vx*2+1, tmx+1, trx, lx, rx, ly, ry);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y) {
    if (ry == ly) {
        if (rx == lx){
            t[vx][vy]++;
            t[vx][vy]%=2;
        }else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void update_x(int vx, int lx, int rx, int x, int y) {
    if (rx != lx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx*2, lx, mx, x, y);
        else
            update_x(vx*2+1, mx+1, rx, x, y);
    }
    update_y(vx, lx, rx, 1, 0, n-1, x, y);
}
