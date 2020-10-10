#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ll n, m, q, line, state, px, py, nx, ny, mx, mxd, mxx;
        scanf("%lld %lld %lld", &n, &m, &q);
        set <ll> x, y;
        multiset <ll> dif, difx;

        set <ll> :: iterator it1, it2;
        multiset <ll> :: iterator it3;

        x.insert(0), x.insert(n);
        y.insert(0), y.insert(m);
        dif.insert(m);
        difx.insert(n);

        for(ll i = 1; i <= q; i++) {
            scanf("%lld %lld", &state, &line);
            if(state == 0) {
                if( x.find(line) == x.end()) {

                    it3 = x.lower_bound(line);
                    px = *(--it3);

                    it3 = x.upper_bound(line);
                    nx = *it3;

                    difx.erase( difx.find(nx - px) );
                    difx.insert(line - px);
                    difx.insert(nx - line);
                    x.insert(line);
                }
            }
            else if(y.find(line) == y.end()) {

                it3 = y.lower_bound(line);
                py = *(--it3);

                it3 = y.upper_bound(line);
                ny = *it3;

                //cout << ny << "  " << py << "  " << line << endl;
                dif.erase( dif.find(ny - py) );
                dif.insert(line - py);
                dif.insert(ny - line);
                y.insert(line);
            }

            mxd = *(--dif.end());
            mxx = *(--difx.end());
            mx = mxd * mxx;

            printf("%lld\n", mx);
        }
    }

    return 0;
}
