/* Li Chao Tree Template
 * Can be used solve Convex Hull Trick problems

 * Adding line (y = mx+c) : O(logn)
 * Query : O(logn)
 
 * To find minimum, use f1(x) < f2(x), min in update & query.
 * To find maximum, use f1(x) > f2(x), max in update & query.

 * The line of tree[node] in range [lo, hi] represents
   that this line gives the best result for point [x, y] range,
   where x <= mid <= y. Here, mid = (lo+hi) / 2.
*/

#define ll long long

const ll sz = 1e5 + 10;
ll pnt[sz]; // 1 based indexing
// This array stores the points (in ascending order) needed to be queried.

struct Line {
    ll m, c;    // y = m*x + c

    inline ll f(ll x) {return m*x + c;}
} tree[4*sz];

bool exist[4*sz];
// This will track the nodes updated.
// Thus query'll be optimized by not traversing
// the non-updated nodes.

void add(ll lo, ll hi, Line line, ll node)
{
    // To initialize the tree, add this line:
    // if(!exist[node]) tree[node] = {m, c};
    // replace m, c with your desired values.
    exist[node] = 1;

    if(lo == hi) {
        if(line.f(pnt[lo]) < tree[node].f(pnt[lo]))
            tree[node] = line;

        return;
    }

    ll mid = lo+hi >> 1;
    bool left = line.f(pnt[lo]) < tree[node].f(pnt[lo]);
    bool m = line.f(pnt[mid]) < tree[node].f(pnt[mid]);

    if(m) swap(tree[node], line);
    // if m == true, new line gives the best answer in point [x,y] range,
    // where x <= mid <= y.

    // left != m means line intersection between new line and
    // tree[node]'s line is occurring in the left side of mid point
    if(left != m) add(lo, mid, line, node<<1);
    else add(mid+1, hi, line, node<<1|1);
}

ll query(ll lo, ll hi, ll idx, ll node)
{
    if(lo == hi)
        return tree[node].f(pnt[idx]);

    ll mid = lo+hi >> 1, ret = tree[node].f(pnt[idx]);

    // We are not traversing the non-updated nodes. Thus query is optimized.
    if(idx <= mid && exist[node<<1]) ret = min(ret, query(lo, mid, idx, node<<1));
    else if(idx > mid && exist[node<<1|1]) ret = min(ret, query(mid+1, hi, idx, node<<1|1));

    return ret;
}

/*
 * To add a line: Call add(1, n, {m, c}, 1)

 * To query for a point x:
   Let, x is in i index of pnt array.
   Call query(1, n, i, 1)

 * [N.B: Query points are in the pnt array from
   index 1 to index n]
*/
