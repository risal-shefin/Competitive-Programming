// Count of numbers of [a,b] range in [L, R] index
#define nsz 100010
#define tsz 6000010 //take 4n + qlogn
ll a[nsz];
ll NEXT_FREE;
ll version[nsz];
ll val[tsz], Left[tsz], Right[tsz];
void build(ll node, ll lo, ll hi)
{
    if(lo == hi) // leaf node
    {
        val[node] = 0;
        return;
    }
    Left[node] = NEXT_FREE++;
    Right[node] = NEXT_FREE++;
    ll mid = (lo + hi) >> 1;
    build(Left[node], lo, mid);
    build(Right[node], mid+1, hi);
    val[node] = val[Left[node]] + val[Right[node]];
}

ll update(ll node, ll lo, ll hi, ll idx, ll v)
{
    if(lo > idx || hi < idx)
        return node; // Out of range, use this node.

    ll nnode = NEXT_FREE++; //Creating a new node, as idx is in [l, r]

    if (lo == hi)    // Leaf Node, create new node and return that.
    {
        val[nnode] = val[node]; //cloning current old leaf node's value to new leaf node
        val[nnode] += v; // adding or subtracting or replacing as needed
        return nnode;
    }
    ll mid = (lo + hi) >> 1;
    // Left[nnode] is new node's Left child, it might end up being the old one too
    // Left[node] is current old node's Left child.
    // So we call to update idx in Left child of old node.
    // And use it's return node as new node's Left child. Same for Right.
    Left[nnode] = update(Left[node], lo, mid, idx, v);
    Right[nnode] = update(Right[node], mid+1, hi, idx, v);
    val[nnode] = val[Left[nnode]] + val[Right[nnode]]; // Update value.
    return nnode; // Return the new node to parent.
}

ll query(ll lnode, ll rnode, ll lo, ll hi, ll l, ll r)
{	
    if(lo > r || hi < l)
        return 0;

    if (lo >= l && hi <= r)
        return val[rnode] - val[lnode];

    ll mid = (lo + hi) >> 1;

    return query(Left[lnode], Left[rnode], lo, mid, l, r)
        +  query(Right[lnode], Right[rnode], mid+1, hi, l, r);
}

// NEXT_FREE = 0
// version[0] = NEXT_FREE++
// build(version[0], 1, n)

// upd(ara[i], 1) -> increment the frequency
// So, version[i] = update(version[i-1], 1, n, i, 1)

// query: Count of numbers of [a,b] range in [L, R] index
// So, ans = query(version[l-1], version[r], 1, n, L, R)
