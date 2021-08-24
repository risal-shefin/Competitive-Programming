#define ll long long
#define siz 100009

struct point {
    ll x, y;
};

point p[siz], hull[2 * siz];
ll sz = 0;

bool cmp(point a, point b) {

    if(a.x != b.x)
        return a.x < b.x;

    return a.y < b.y;
}

ll cross (point a, point b, point c) {

    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void ConvexHull(ll n) {

    sz = 0;
    sort(p, p + n, cmp);

    /// Building lower hull
    for(ll i = 0; i < n; i++) {
        while (sz > 1 && cross(hull[sz - 2], hull[sz - 1], p[i]) <= 0) --sz;   /// use < 0 for taking co-linear points
        hull[sz++] = p[i];
    }

    /// Building upper hull
    for(int i = n - 2, j = sz + 1; i >= 0; i--) {
        while (sz >= j && cross(hull[sz - 2], hull[sz - 1], p[i]) <= 0) --sz;  /// use < 0 for taking co-linear points
        hull[sz++] = p[i];
    }

    /// last point is same as first point. so, sz--
    /// sz is the size of convex hull
    sz--;
}
