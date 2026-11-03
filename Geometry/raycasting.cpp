bool inSegment(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x3 >= min(x1,x2) && x3 <= max(x1,x2)) && (y3 >= min(y1,y2) && y3 <= max(y1,y2));
}
 
bool raycasting(vector<P> points, vector<P> polygon, int n) {
 
    P a = points[i];
    int intersections = 0;
    bool bound = false;

    for(int j = 0; j < n; j++) {
        P b1 = polygon[j];
        P b2;

        if(j < n-1) b2 = polygon[j+1];
        else b2 = polygon[0];

        if ((a.Y > min(b1.Y, b2.Y)) && (a.Y <= max(b1.Y, b2.Y))) {
            ld x_int = b1.X + (ld)(b2.X - b1.X) * (a.Y - b1.Y) / (b2.Y - b1.Y);
            if (x_int > a.X)
                intersections++;
        }

        if((conj(a-b1)*(b2-b1)).Y == 0 && inSegment(b1.X,b1.Y,b2.X,b2.Y,a.X,a.Y))
            bound = true;
    }
    
    return intersections % 2 != 0;
}