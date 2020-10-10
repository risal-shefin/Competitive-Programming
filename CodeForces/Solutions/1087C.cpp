#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <ll, ll>

struct point {
    ll x, y;
    point() {}
    point(ll _x, ll _y) {
        x = _x;
        y = _y;
    }

} ara[1100009];

struct node {
    ll x, y, c;
    node(ll _x, ll _y, ll _c) {
        x = _x;
        y = _y;
        c = _c;
    }

};

ll msk[1009][1009], par[1100009];
ll ase[1009][1009], vis[1009][1009], cost[1009][1009];
pii abc[3];

ll row[4] = {1, -1, 0, 0};
ll col[4] = {0, 0, 1, -1};

bool operator <(node a, node b)

{
    return a.c > b.c;
}

ll dist(ll x, ll y, ll a, ll b)

{
    return (x - a) * (x - a) + (y - b) * (y - b);
}

int main()

{
    ll indx = 1;
    for(ll i = 0; i <= 1000; i++){
        for(ll j = 0; j <= 1000; j++) {
            ara[indx].x = i;
            ara[indx].y = j;
            msk[i][j] = indx;
            indx++;

            cost[i][j] = 1e18;
        }

    }

    ll x, y, x1, y1, x2, y2, x3, y3;
    for(ll i = 0; i < 3; i++)
        cin >> abc[i].first >> abc[i].second;
    sort(abc, abc + 3);

    x1 = abc[0].first, y1 = abc[0].second;
    x2 = abc[1].first, y2 = abc[1].second;
    x3 = abc[2].first, y3 = abc[2].second;

//    if(dist(x1, y1, x2, y2) > dist(x1, y1, x3, y3)) {
//        swap(x2, x3);
//        swap(y2, y3);
//    }

    queue <point> q;
    q.push(point(x1, y1));
    vis[x1][y1] = 1;

    while(!q.empty()) {
        point u = q.front();
        q.pop();

        ll p = msk[u.x][u.y];
        bool chk = 0;
        for(ll i = 0; i < 4; i++) {
            ll r = u.x + row[i];
            ll c = u.y + col[i];

            if(r < 0 || c < 0 || r > 1000 || c > 1000)
                continue;

            if(vis[r][c] == 0) {
                vis[r][c] = 1;
                ll n1 = msk[r][c];
                //cout << ara[n1].x << "  " << ara[n1].y << " " << n1 << endl;
                par[n1] = p;
                if(r == x2 && c == y2) {
                    chk = 1;
                    break;
                }
                q.push( point(r, c) );
            }
        }
        if(chk)
            break;

    }

    memset(vis, 0, sizeof(vis));
    set <int> sob;

    ll nowx = x2, nowy = y2;
    while(1) {
        vis[nowx][nowy] = 1;
        ll mk = msk[nowx][nowy];
        sob.insert(mk);

        if(nowx == x1 && nowy == y1)
            break;

        ll pmk = par[mk];
        nowx = ara[pmk].x;
        nowy = ara[pmk].y;
    }

    priority_queue <node> pq;
    pq.push( node(x2, y2, 0));
    cost[x2][y2] = 0;
    while(!pq.empty()) {
        node u = pq.top();
        pq.pop();

        ll p = msk[u.x][u.y];
        if(cost[u.x][u.y] != u.c)
            continue;
        for(ll i = 0; i < 4; i++) {
            ll r = u.x + row[i];
            ll c = u.y + col[i];

            if(r < 0 || c < 0 || r > 1000 || c > 1000)
                continue;

            ll nc = u.c + (vis[r][c] != 1);
            if(nc < cost[r][c]) {
                cost[r][c] = nc;
                ll n1 = msk[r][c];
                //cout << ara[n1].x << "  " << ara[n1].y << " " << n1 << endl;
                par[n1] = p;
                pq.push( node(r, c, nc) );
            }
        }
    }

    nowx = x3, nowy = y3;
    while(1) {
        ll mk = msk[nowx][nowy];
        sob.insert(mk);

        if(nowx == x2 && nowy == y2)
            break;

        ll pmk = par[mk];
        nowx = ara[pmk].x;
        nowy = ara[pmk].y;
    }

    cout << sob.size() << endl;
    for(auto it = sob.begin(); it != sob.end(); it++) {
        ll no = *it;

        printf("%lld %lld\n", ara[no].x, ara[no].y);
    }

    return 0;
}