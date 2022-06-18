/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form mx+c, and query max values at points x.
                For min query, add line in (-m, -c) format. You will get -ans.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */
struct Line {
	mutable ll m, c, p;
	bool isQuery;
	bool operator<(const Line& o) const {
	    if(o.isQuery)
            return p < o.p;
	    return m < o.m;
    }
};

struct LineContainer : multiset<Line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->m == y->m) x->p = x->c > y->c ? inf : -inf;
		else x->p = div(y->c - x->c, x->m - y->m);
		return x->p >= y->p;
	}
	void add(ll m, ll c) {
		auto z = insert({m, c, 0, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		if(empty()) return inf;
		Line q; q.p = x, q.isQuery = 1;
		auto l = *lower_bound(q);
		return l.m * x + l.c;
	}
};
